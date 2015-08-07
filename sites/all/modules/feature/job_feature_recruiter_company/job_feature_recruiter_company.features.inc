<?php
/**
 * @file
 * job_feature_recruiter_company.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function job_feature_recruiter_company_image_default_styles() {
  $styles = array();

  // Exported image style: company_logo_on_listings.
  $styles['company_logo_on_listings'] = array(
    'label' => 'Company logo on listings (137x92)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 137,
          'height' => 92,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_profile2_type().
 */
function job_feature_recruiter_company_default_profile2_type() {
  $items = array();
  $items['company'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "company",
    "label" : "Company",
    "weight" : "0",
    "data" : {
      "registration" : 0,
      "roles" : { "30037204" : "30037204", "100482362" : "100482362" },
      "use_page" : 1
    },
    "rdf_mapping" : []
  }');
  return $items;
}
