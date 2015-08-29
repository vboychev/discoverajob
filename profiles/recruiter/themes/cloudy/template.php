<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * Cloudy theme.
 */

/**
 * Implements hook_form_alter().
 */
function cloudy_form_alter(&$form, $form_state, $form_id) {
  // Force certain forms to be stacked.
  if (in_array($form_id, array('user_pass', 'user_register_form', 'user_login', 'user_login_block'))) {
    $form['#attributes']['class'][] = 'form-stacked';
  }

  if ($form_id == 'search_api_saved_searches_save_form') {
    $form['notify_interval']['#default_value'] = 604800;  //Weekly is default.
  }
}

/**
 * Implements hook_css_alter().
 */
function cloudy_css_alter(&$css) {
  unset($css[drupal_get_path('module', 'addressfield') . '/addressfield.css']);
  unset($css[drupal_get_path('module', 'date_api') . '/date.css']);
}

function cloudy_preprocess_menu_link(&$variables) {
  if (!empty($variables['element']['#theme']) && $variables['element']['#theme'] == 'menu_link__menu_login_menu' && $variables['element']['#href'] == 'user/register') {
    $recruiter_urls = array(
      'recruiter',
      'recruiter/applications',
      'recruiter/applications/all',
      'recruiter/applications/shortlisted',
      'recruiter/applications/rejected',
      'manage/job',
      'search/resume',
      'profile-company'
    );

    if (in_array(current_path(), $recruiter_urls)) {
      $variables['element']['#href'] = 'user/register/recruiter';
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function cloudy_form_user_profile_form_alter(&$form, $form_state) {
  // Hide language settings on user profile page.
  unset($form['locale']);
}
