<?php

/**
 * Implements hook_process().
 */
function cloudy_process_entity(&$variables) {
  if ($variables['entity_type'] == 'field_collection_item'
     && $variables['elements']['#bundle'] == 'field_resume_personal_info') {
    $content = &$variables['content'];
    if (isset($variables['elements']['#entity']->hostEntity()->field_additional_fields[LANGUAGE_NONE][0]['value'])) {
      $faf = $variables['elements']['#entity']->hostEntity()->field_additional_fields[LANGUAGE_NONE][0]['value'];
      $faf = field_collection_item_load($faf);

      $display = array(
        'label' => 'hidden',
        'type' => 'image',
        'settings' =>  array(
          'image_style' => 'thumbnail',
        ),
      );

      if (!empty($faf->field_resume_photo)) {
        $content['field_resume_photo'] = field_view_field('field_collection_item', $faf, 'field_resume_photo', $display);
      }
    }
    
    $name_fields = array(
      'field_resume_salutation',
      'field_resume_firstname',
      'field_resume_lastname'
    );
    foreach ($name_fields as $name_field) {
      if (isset($content[$name_field])) {
        $name = (empty($name) ? '' : $name . ' ') . $content[$name_field][0]['#markup'];
        hide($content[$name_field]);
      }
    }
    $content['full_name']['#markup'] = $name;
  }
}
