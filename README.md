# Empty field groups

This module provides a way to show empty field groups that would otherwise be
hidden. It achieves this by appending new settings to existing display
formatters. These settings allow you to display a value using either:

* custom text, or label, as defined by the field group administrator;
* to show the results of a custom callback;

## Installation

1. Install this module using the official Backdrop CMS instructions at
<https://backdropcms.org/guide/modules>.

## Configuration

The module can be configured on each entity's field group display formatter.

## API

For specific use-cases, you can define a custom callback to generate dynamic
content.

First, implement `hook_empty_field_groups()`. This returns an array indexed by the
class name that implements the handler.

```php
/**
 * Implements hook_empty_field_groups().
 */
function HOOK_empty_field_groups() {
  $items = array(
    'CurrentTimeEmptyFieldGroupText' => array(
      'title' => t('Display current time if empty'),
    ),
  );
  return $items;
}
```

Create a new concrete class that extends the abstract class EmptyFieldGroupHandler.

```php
/**
 * @file
 * Contains the CurrentTimeEmptyFieldGroupText plugin for EmptyFieldGroupHandler.
 */

/**
 * Defines CurrentTimeEmptyFieldGroupText class.
 */
class CurrentTimeEmptyFieldGroupText extends EmptyFieldGroupHandler {

  /**
   * {@inheritdoc}
   */
  public function react($context) {
    return format_date(time());
  }

  /**
   * {@inheritdoc}
   */
  public function summaryText() {
    return t('Empty Text: current time');
  }

}
```

Register this class in your module:

```php
/**
 * Implements hook_autoload_info().
 */
function YOUR_MODULE_autoload_info() {
  return array(
    'CurrentTimeEmptyFieldGroupText' => 'plugins/empty_field_groups_handler_current_time.inc',
  );
}
```

The context has the entity_type, entity, view_mode as well as the group info.

If the callback is empty or a zero-length string, the empty field group will not be
rendered.

## License

This project is GPL v2 software. See the LICENSE.txt file in this directory
for complete text.

## Maintainers

* [Herb v/d Dool](https://github.com/herbdool)

## Credits

Inspired by Empty Fields module.
