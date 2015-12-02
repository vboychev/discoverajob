<?php

/**
 * @file
 * Page callbacks for the Contact module settings.
 */

/**
 * Form constructor for the site-wide contact form configuration.
 */
function discoverajob_config_contact_form($form, &$form_state) {
  $form['discoverajob_contact_form_mail'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail address which will receive mails from contact form'),
    '#maxlength' => 255,
    '#required' => TRUE,
    '#default_value' => variable_get('discoverajob_contact_form_mail', 'office@discoverajob.bg'),
  );
  $defaults = array(
    'value' => '',
    'format' => filter_default_format(),
  );
  $discoverajob_contact_form_contacts = variable_get('discoverajob_contact_form_contacts', $defaults);
  $form['discoverajob_contact_form_contacts'] = array(
    '#type' => 'text_format',
    '#format' => $discoverajob_contact_form_contacts['format'],
    '#title' => t('Contact form contacts information'),
    '#required' => TRUE,
    '#default_value' => $discoverajob_contact_form_contacts['value'],
  );
  $discoverajob_contact_form_help = variable_get('discoverajob_contact_form_help', $defaults);
  $form['discoverajob_contact_form_help'] = array(
    '#type' => 'text_format',
    '#format' => $discoverajob_contact_form_help['format'],
    '#title' => t('Contact form help text'),
    '#required' => TRUE,
    '#default_value' => $discoverajob_contact_form_help['value'],
  );

  return system_settings_form($form);
}
