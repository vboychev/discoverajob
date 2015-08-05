<?php

/**
 * @file
 * Contains some hooks that are used during installation.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function recruiter_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate some fields.
  $form['site_information']['site_name']['#default_value'] = t('Recruiter');
  $form['site_information']['site_mail']['#default_value'] = 'admin@' . ($_SERVER['HTTP_HOST'] != 'localhost' ? $_SERVER['HTTP_HOST'] : 'example.com');

  // Add checkbox for example content.
  $form['recruiter'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#title' => t('Recruiter'),
  );

  $form['recruiter']['recruiter_demo_content'] = array(
    '#type' => 'checkbox',
    '#title' => t('Install demo content'),
    '#description' => t('Check this option to enable demonstration content for Recruiter to get your site up and running quickly.'),
    '#default_value' => TRUE,
  );

  // The user needs to set a private file directory. This is a requirement for
  // the resume feature and the directory is needed during the import of demo
  // data.
  $form['file_system'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#title' => t('File system'),
  );
  $form['file_system']['file_private_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Private file system path'),
    '#default_value' => variable_get('file_private_path', 'sites/default/files/private'),
    '#maxlength' => 255,
    '#description' => t('An existing local file system path for storing private files which is needed by the resume feature and during the import of demo data. It should be writable by Drupal and not accessible over the web. Note that non-Apache web servers may need additional configuration to secure private file directories. See the online handbook for <a href="@handbook">more information about securing private files</a>.', array('@handbook' => 'http://drupal.org/documentation/modules/file')),
    '#after_build' => array('system_check_directory'),
    '#required' => TRUE,
  );

  $form['#submit'][] = 'recruiter_install_configure_form_submit';
}

/**
 * Submit callback.
 */
function recruiter_install_configure_form_submit(&$form, &$form_state) {
  // Set variable to install or not demo content.
  variable_set('recruiter_install_demo_content', $form_state['values']['recruiter_demo_content']);

  // Set the private files directory variable.
  variable_set('file_private_path', $form_state['values']['file_private_path']);
}
