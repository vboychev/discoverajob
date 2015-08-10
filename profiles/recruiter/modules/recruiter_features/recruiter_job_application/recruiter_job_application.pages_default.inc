<?php
/**
 * @file
 * recruiter_job_application.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function recruiter_job_application_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'job_application_recruiter';
  $page->task = 'page';
  $page->admin_title = 'Job applications recruiter';
  $page->admin_description = '';
  $page->path = 'recruiter/applications/!uid/!job';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'All',
    'name' => 'navigation',
    'weight' => '-10',
    'parent' => array(
      'type' => 'normal',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'uid' => array(
      'id' => 1,
      'identifier' => 'User: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
    'job' => array(
      'id' => 1,
      'identifier' => 'Content: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_job_application_recruiter_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'job_application_recruiter';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Applications (Admin)',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '1',
          ),
          'context' => 'argument_entity_id:user_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 30037204,
              1 => 29617163,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '0',
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Received applications of %uid:name';
  $display->uuid = 'd6a51ca9-6962-f674-d149-0b2e76d29c7d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a413a994-4650-6cc4-c1c5-90e3a6c840ce';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'job_application_recruiter-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:user_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a413a994-4650-6cc4-c1c5-90e3a6c840ce';
    $display->content['new-a413a994-4650-6cc4-c1c5-90e3a6c840ce'] = $pane;
    $display->panels['middle'][0] = 'new-a413a994-4650-6cc4-c1c5-90e3a6c840ce';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_job_application_recruiter_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'job_application_recruiter';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Applications for job',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '1',
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_access',
          'settings' => array(
            'type' => 'view',
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 30037204,
              1 => 100482362,
              2 => 29617163,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Applications for job %job:title';
  $display->uuid = 'd6a51ca9-6962-f674-d149-0b2e76d29c71';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a413a994-4650-6cc4-c1c5-90e3a6c840c1';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'job_application_recruiter-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'context_user_1',
        1 => 'argument_entity_id:node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a413a994-4650-6cc4-c1c5-90e3a6c840c1';
    $display->content['new-a413a994-4650-6cc4-c1c5-90e3a6c840c1'] = $pane;
    $display->panels['middle'][0] = 'new-a413a994-4650-6cc4-c1c5-90e3a6c840c1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_job_application_recruiter_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'job_application_recruiter';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Applications',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Applications';
  $display->uuid = 'd6a51ca9-6962-f674-d149-0b2e76d29c72';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d8c694f4-913d-bb64-cd5e-20f293856f6d';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'job_application_recruiter-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'context_user_1',
        1 => 'empty',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd8c694f4-913d-bb64-cd5e-20f293856f6d';
    $display->content['new-d8c694f4-913d-bb64-cd5e-20f293856f6d'] = $pane;
    $display->panels['middle'][0] = 'new-d8c694f4-913d-bb64-cd5e-20f293856f6d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_job_application_recruiter__anonymous';
  $handler->task = 'page';
  $handler->subtask = 'job_application_recruiter';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Anonymous',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'anonymous',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = ' Job applications';
  $display->uuid = '2b58974a-0b24-4eb5-bce5-a8ad468af994';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3870b460-bc4f-437d-86a2-04c85492c584';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>You need to login as recruiter in order to see job applications.</p>',
      'format' => 'filtered_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3870b460-bc4f-437d-86a2-04c85492c584';
    $display->content['new-3870b460-bc4f-437d-86a2-04c85492c584'] = $pane;
    $display->panels['middle'][0] = 'new-3870b460-bc4f-437d-86a2-04c85492c584';
    $pane = new stdClass();
    $pane->pid = 'new-2f7009d6-75bf-43ba-b6d3-9c70dfc9ca2c';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'user-login';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2f7009d6-75bf-43ba-b6d3-9c70dfc9ca2c';
    $display->content['new-2f7009d6-75bf-43ba-b6d3-9c70dfc9ca2c'] = $pane;
    $display->panels['middle'][1] = 'new-2f7009d6-75bf-43ba-b6d3-9c70dfc9ca2c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2f7009d6-75bf-43ba-b6d3-9c70dfc9ca2c';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['job_application_recruiter'] = $page;

  return $pages;

}
