<?php
/**
 * @file
 * luggage_story.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function luggage_story_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function luggage_story_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function luggage_story_image_default_styles() {
  $styles = array();

  // Exported image style: story_thumbnail.
  $styles['story_thumbnail'] = array(
    'label' => 'Story Thumbnail (640x500)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 500,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function luggage_story_node_info() {
  $items = array(
    'story' => array(
      'name' => t('Feature Story'),
      'base' => 'node_content',
      'description' => t('A feature or promotional story.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
