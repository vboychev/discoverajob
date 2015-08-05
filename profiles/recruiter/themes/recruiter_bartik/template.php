<?php
// $Id$

/**
 * Implements theme_field__field_type().
 */
function recruiter_bartik_field__taxonomy_term_reference($variables) {
  // Use default output instead of bartiks weird taxnomy field output
  return theme_field($variables);
}

/**
 * Implements hook_preprocess_entity().
 */
function recruiter_bartik_preprocess_entity($variables) {
  if ($variables['entity_type'] == 'profile2') {
    // If resume teaser is shown, include specific css style.
    if ($variables['profile2']->type == 'resume' && $variables['view_mode'] == 'teaser') {
      drupal_add_css(drupal_get_path('theme', 'recruiter_bartik') . '/css/recruiter_resume_teaser.css');
    }
    elseif ($variables['profile2']->type == 'resume' && $variables['view_mode'] == 'page') {
      drupal_add_css(drupal_get_path('theme', 'recruiter_bartik') . '/css/recruiter_resume_page.css');
    }
  }
}
