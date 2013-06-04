<?php

/**
 * Administration page for baidu assoc map
 */
function bmap_assoc_settings() {
  $form = array();
  $form['bmap_assoc_types'] = array(
    '#type' => 'textarea',
    '#title' => t('Associate node types'),
    '#default_value' => variable_get('bmap_assoc_types', ''),
  );
  return system_settings_form($form);
}

/**
 * Display bmap assoc admin page
 */
function bmap_assoc_manage() {
  $view = views_get_view('bmap_assoc', 'default');
  $view->override_url = $_GET['q'];
  return $view->preview();
}

/**
 * Returns a bmap assoc submission form.
 */
function bmap_assoc_add() {
  $bmapAssoc = entity_get_controller('bmap_assoc')->create();
  $output = drupal_get_form('bmap_assoc_form', $bmapAssoc);
  return $output;
}

/**
 * Bmap assoc view page.
 */
function bmap_assoc_page_view($bmapAssoc, $view_mode = 'full') {
  $build = $bmapAssoc->view($view_mode);
  if ($view_mode == 'full') {
    $build['bmap'][$bmapAssoc->id]['bid'] = array(
      '#markup' => '<div class="field field-type-text field-label-above"><div class="field-label">Bid:</div><div class="field-items"><div class="field-item even">'.filter_xss($bmapAssoc->bid).'</div></div></div>',
      '#weight' => -20,
    );
    $build['bmap'][$bmapAssoc->id]['nid'] = array(
      '#markup' => '<div class="field field-type-text field-label-above"><div class="field-label">Nid:</div><div class="field-items"><div class="field-item even">'.filter_xss($bmapAssoc->nid).'</div></div></div>',
      '#weight' => -10,
    );
  }
  return $build;
}

/**
 * Bmap assoc edit page.
 */
function bmap_assoc_page_edit($bmapAssoc) {
  return drupal_get_form('bmap_assoc_form', $bmapAssoc);
}

/**
 * Confirm form for deleting a bmap assoc.
 */
function bmap_assoc_delete_confirm_form($form, &$form_state, $bmapAssoc) {
  $form_state += array('bmap_assoc' => $bmapAssoc);
  $confirm_question = t('Are you sure you want to delete bmap assoc for Bid:%bid, Nid:%nid ?', array('%bid' => $bmapAssoc->bid, '%nid' => $bmapAssoc->nid));
  return confirm_form($form, $confirm_question, 'bmap_assoc/'.$bmapAssoc->id);
}

/**
 * Bmap delete confirm form submit handler.
 */
function bmap_assoc_delete_confirm_form_submit($form, &$form_state) {
  $bmapAssoc = $form_state['bmap_assoc'];
  $bmapAssoc->delete();
  drupal_set_message(t('Delete bmap assoc for Bid: %bid , Nid: %nid .', array('%bid' => $bmapAssoc->bid, '%nid' => $bmapAssoc->nid)));
  $form_state['redirect'] = 'admin/structure/bmap_assoc';
}