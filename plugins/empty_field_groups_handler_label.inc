<?php
/**
 * @file
 * Contains the EntityLabelEmptyFieldGroupHandler plugin for Empty Field Groups
 * module.
 */

/**
 * Defines EntityLabelEmptyFieldGroupHandler.
 */
class EntityLabelEmptyFieldGroupHandler extends EmptyFieldGroupHandler {

  /**
   * {@inheritdoc}
   */
  public function defaults() {
    return array(
      'display' => 'text',
    );
  }

  /**
   * {@inheritdoc}
   */
  public function form($group) {
    $form['display'] = array(
      '#type' => 'radios',
      '#title' => t('Display options'),
      '#default_value' => isset($this->options['display']) ? $this->options['display'] : 'text',
      '#options' => array(
        'text' => t('Text only'),
        'link' => t('Link'),
      ),
      '#required' => TRUE,
    );

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function react($context) {
    if (!$context['entity']) {
      return '';
    }
    $title = entity_label($context['entity_type'], $context['entity']);
    switch ($this->options['display']) {
      case 'link':
        if ($url = (array) entity_uri($context['entity_type'], $context['entity'])) {
          return l($title, $url['path'], $url['options']);
        }
        // Fall through.

      case 'text':
      default:
        return check_plain($title);
    }
  }
}
