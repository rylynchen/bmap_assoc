<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 */


class bmap_assoc_handler_edit_link_field extends bmap_assoc_handler_link_field {
  
  function construct() {
    parent::construct();
  }

  function render($values) {
    // Check access
    if (!user_access('edit bmap assoc')) {
      return;
    }
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $id = $values->{$this->aliases['id']};
    return l($text, 'bmap_assoc/' . $id . '/edit', array('query' => array('destination' => 'admin/structure/bmap/assoc')));
  }
}
