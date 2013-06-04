<?php

/**
 * Implements hook_views_default_views().
 */
function bmap_assoc_views_default_views() {
  $view = new view();
  $view->name = 'bmap_assoc';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bmap_assoc';
  $view->human_name = 'Bmap Assoc';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Bmap Assoc: Bmap assoc ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'bmap_assoc';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: Bmap Assoc: Bid */
  $handler->display->display_options['fields']['bid']['id'] = 'bid';
  $handler->display->display_options['fields']['bid']['table'] = 'bmap_assoc';
  $handler->display->display_options['fields']['bid']['field'] = 'bid';
  $handler->display->display_options['fields']['bid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['bid']['alter']['path'] = 'bmap/[bid]';
  $handler->display->display_options['fields']['bid']['alter']['target'] = '_blank';
  /* Field: Bmap Assoc: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'bmap_assoc';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nid']['alter']['target'] = '_blank';
  /* Field: Bmap Assoc: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'bmap_assoc';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['label'] = 'Operations';
  /* Filter criterion: Bmap Assoc: Bid */
  $handler->display->display_options['filters']['bid']['id'] = 'bid';
  $handler->display->display_options['filters']['bid']['table'] = 'bmap_assoc';
  $handler->display->display_options['filters']['bid']['field'] = 'bid';
  $handler->display->display_options['filters']['bid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bid']['expose']['operator_id'] = 'bid_op';
  $handler->display->display_options['filters']['bid']['expose']['label'] = 'Bid';
  $handler->display->display_options['filters']['bid']['expose']['operator'] = 'bid_op';
  $handler->display->display_options['filters']['bid']['expose']['identifier'] = 'bid';
  $handler->display->display_options['filters']['bid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Bmap Assoc: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'bmap_assoc';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Nid';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  $views[$view->name] = $view;
  return $views;
}