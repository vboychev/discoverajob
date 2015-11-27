<?php

/**
 * @file
 * Page callbacks for the Contact module.
 */

/**
 * Form constructor for the site-wide contact form.
 *
 * @see discoverajob_contact_site_form_validate()
 * @see discoverajob_contact_site_form_submit()
 * @ingroup forms
 */
function discoverajob_contact_form($form, &$form_state) {
  global $user;

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Your name'),
    '#maxlength' => 255,
    '#default_value' => $user->uid ? format_username($user) : '',
    '#required' => TRUE,
  );
  $form['mail'] = array(
    '#type' => 'textfield',
    '#title' => t('Your e-mail address'),
    '#maxlength' => 255,
    '#default_value' => $user->uid ? $user->mail : '',
    '#required' => TRUE,
  );
  $form['message'] = array(
    '#type' => 'textarea',
    '#title' => t('Message'),
    '#required' => TRUE,
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send message'),
  );

  return $form;
}

/**
 * Form validation handler for discoverajob_contact_site_form().
 *
 * @see discoverajob_contact_site_form_submit()
 */
function discoverajob_contact_site_form_validate($form, &$form_state) {
  if (!valid_email_address($form_state['values']['mail'])) {
    form_set_error('mail', t('You must enter a valid e-mail address.'));
  }
}

/**
 * Form submission handler for discoverajob_contact_site_form().
 *
 * @see discoverajob_contact_site_form_validate()
 */
function discoverajob_contact_site_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  // Get the to and from e-mail addresses.
  $to = ''; // TODO: get email form settings.
  $from = $values['sender']->mail;

  // Send the e-mail to the recipients using the site default language.
  drupal_mail('');

  // Jump to home page rather than back to contact page to avoid
  // contradictory messages if flood control has been activated.
  drupal_set_message(t('Your message has been sent.'));
  $form_state['redirect'] = '';
}
