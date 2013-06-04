<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying deletes links
 * as fields
 */


class bmap_assoc_handler_delete_link_field extends bmap_assoc_handler_link_field {

  function construct() {
    parent::construct();
  }

  function render($values) {
    // Check access
    if (!user_access('delete bmap assoc')) {
      return;
    }
    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    $id = $values->{$this->aliases['id']};
    return l($text, 'bmap_assoc/' . $id . '/delete');
  }
}
