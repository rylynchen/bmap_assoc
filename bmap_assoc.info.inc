<?php

/**
 * @file
 * Provides Entity metadata integration.
 */

/**
 * Extend the defaults.
 */
class BmapAssocMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['bid'] = array(
      'label' => t('Bid'),
      'description' => t('The {bmap}.bid.'),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer bmap assoc',
      'schema field' => 'bid',
    );
    $properties['nid'] = array(
      'label' => t('Nid'),
      'description' => t('The {node}.nid.'),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer bmap assoc',
      'schema field' => 'nid',
    );
    return $info;
  }
}