<?php
/**
 * @file
 * job_feature_dependency.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function job_feature_dependency_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use search_api_autocomplete for search_api_views_front_page_job_search'.
  $permissions['use search_api_autocomplete for search_api_views_front_page_job_search'] = array(
    'name' => 'use search_api_autocomplete for search_api_views_front_page_job_search',
    'roles' => array(),
    'module' => 'search_api_autocomplete',
  );

  // Exported permission: 'use search_api_autocomplete for search_api_views_job_search'.
  $permissions['use search_api_autocomplete for search_api_views_job_search'] = array(
    'name' => 'use search_api_autocomplete for search_api_views_job_search',
    'roles' => array(),
    'module' => 'search_api_autocomplete',
  );

  // Exported permission: 'use search_api_autocomplete for search_api_views_resume_search'.
  $permissions['use search_api_autocomplete for search_api_views_resume_search'] = array(
    'name' => 'use search_api_autocomplete for search_api_views_resume_search',
    'roles' => array(),
    'module' => 'search_api_autocomplete',
  );

  return $permissions;
}
