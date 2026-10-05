<?php
/**
 * @file
 * Contains the base class for empty field group handler classes.
 */

/**
 * Abstract base class defining an empty field group handler.
 *
 * Defines a way to easily create empty field group reaction plugins.
 *
 * @see field_empty_handler_text().
 */
abstract class EmptyFieldGroupHandler {

  /**
   * @var array
   */
  public $options;

  /**
   * Create a new EmptyFieldGroupHandler.
   */
  public function __construct() {
    $this->options = $this->defaults();
  }

  /**
   * Default options that map to FAPI elements in
   * EmptyFieldGroupHandler::form().
   *
   * @return array
   *   An array of default_values for the form below. Key names must match.
   */
  public function defaults() {
    return array();
  }

  /**
   * Provide FAPI elements to configure the empty field group rendering.
   *
   * @param object $group
   *   The group object.
   *
   * @return array
   *   A FAPI array to be used in configuration of this empty text plugin.
   */
  public function form($group) {
    return array();
  }

  /**
   * Provide a reaction. Set the content of the field group.
   *
   * @param array $context
   *
   * @return string
   *   A rendered string of html for display.
   */
  abstract public function react($context);
}
