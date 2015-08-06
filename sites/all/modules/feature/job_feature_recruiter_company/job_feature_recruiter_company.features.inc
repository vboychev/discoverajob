<?php
/**
 * @file
 * job_feature_recruiter_company.features.inc
 */

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
