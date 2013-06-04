<?php

/**
 * Implements hook_views_data()
 */
function bmap_assoc_views_data_alter(&$data) {
  $data['bmap_assoc']['link_bmap_assoc'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the bmap assoc.'),
      'handler' => 'bmap_assoc_handler_link_field',
    ),
  );
  $data['bmap_assoc']['edit_bmap_assoc'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the bmap assoc.'),
      'handler' => 'bmap_assoc_handler_edit_link_field',
    ),
  );
  $data['bmap_assoc']['delete_bmap_assoc'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the bmap assoc.'),
      'handler' => 'bmap_assoc_handler_delete_link_field',
    ),
  );
  // This content of this field are decided based on the menu structure that
  // follows bmaps/bmap/%bmap_bid/op
  $data['bmap_assoc']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this bmap assoc.'),
      'handler' => 'bmap_assoc_handler_bmap_assoc_operations_field',
    ),
  );
}