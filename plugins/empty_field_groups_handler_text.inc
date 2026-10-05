<?php
/**
 * @file
 * Contains the EmptyFieldGroupText plugin for EmptyFieldGroupHandler.
 */

/**
 * Defines EmptyFieldGroupText.
 */
class EmptyFieldGroupText extends EmptyFieldGroupHandler {

  /**
   * {@inheritdoc}
   */
  public function defaults() {
    return array(
      'empty_text' => '',
    );
  }

  /**
   * {@inheritdoc}
   */
  public function form($group) {
    $form['empty_text'] = array(
      '#type' => 'textarea',
      '#title' => t('Display Custom Text'),
      '#default_value' => isset($this->options['empty_text']) ? $this->options['empty_text'] : '',
      '#description' => t('Display text if the field is empty.'),
    );

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function react($context) {
    global $user;
    $group = $context['group'];
    $args = array(
      $context['entity_type'] => $context['entity'],
      'user' => $user,
      'group' => $group,
    );
    $text = $this->options['empty_text'];
    $text = token_replace($text, $args, array('clear' => TRUE));
    return filter_xss_admin($text);
  }

}
