<?php

/**
 * @file
 * Admin forms.
 */

/**
 * Generates admin form.
 */
function islandora_dimensions_admin_form($form, &$form_state) {
  drupal_add_js('https://badge.dimensions.ai/badge.js', 'external');
  drupal_add_js(drupal_get_path('module', 'islandora_dimensions') . '/js/dimensions.js');

  $badge_styles = array(
    "small_rectangle" => "Small rectangle",
    "large_rectangle" => "Large rectangle",
    "small_circle" => "Small circle",
    "medium_circle" => "Medium circle",
    "large_circle" => "Large circle",
  );

  $form['islandora_dimensions_badge'] = array(
    '#type' => 'select',
    '#title' => t('Dimensions Badge'),
    '#options' => $badge_styles,
    '#description' => t('Name of the badge style to use when displaying the dimensions information.'),
    '#default_value' => variable_get('islandora_dimensions_badge', 'small_circle'),
    '#ajax' => array(
      'wrapper' => 'badge-preview',
      'callback' => 'islandora_dimensions_preview_badge',
      'method' => 'replace',
      'event' => 'change',
    ),
  );

  $form['islandora_dimensions_legend'] = array(
    '#type' => 'select',
    '#title' => t('Dimensions legend'),
    '#description' => t('Legend direction for extra information.'),
    '#options' => array(
      "" => "None",
      "hover-top" => "Top",
      "hover-right" => "Right",
      "hover-bottom" => "Bottom",
      "hover-left" => "Left",
    ),
    '#default_value' => variable_get('islandora_dimensions_legend', 'hover-right'),
    '#ajax' => array(
      'wrapper' => '__dimensions_badge_embed__',
      'callback' => 'islandora_dimensions_preview_badge',
      'method' => 'replace',
      'event' => 'change',
    ),
  );

  $form['islandora_dimensions_wrapper'] = array(
    '#type' => 'item',
    '#title' => t('Example badge'),
    '#prefix' => '<span class="__dimensions_badge_embed__">',
    '#suffix' => '</span>',
  );

  $badge = !empty($form_state['values']['islandora_dimensions_badge']) ?
    $form_state['values']['islandora_dimensions_badge'] :
    variable_get('islandora_dimensions_badge', '2');
  $legend = !empty($form_state['values']['islandora_dimensions_legend']) ?
    $form_state['values']['islandora_dimensions_legend'] :
    variable_get('islandora_dimensions_legend', 'hover-right');
  $sample_doi = "10.1038/nature.2014.14583";

  $form['islandora_dimensions_wrapper']['islandora_dimensions_badge_preview'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('__dimensions_badge_embed__'),
      'data-doi' => $sample_doi,
      'data-legend' => $legend,
      'data-style' => $badge,
      'data-hide-zero-citations' => "true",
    ),
  );
  return system_settings_form($form);
}

/**
 * Admin form Ajax callback.
 *
 * @param array $form
 *   The Drupal form object.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return array
 *   The render array.
 */
function islandora_dimensions_preview_badge(array $form, array $form_state) {
  $commands = array();
  // Replaces "return $form['islandora_dimensions_wrapper'];".
  // Specifies the same id in $form['islandora_dimensions_wrapper']['#prefix'].
  $commands[] = ajax_command_html('#badge-preview', render($form['islandora_dimensions_wrapper']));

  // This is what will call our JS command.
  $commands[] = array(
    // The command in my JS file.
    'command' => 'islandoradimensionsRenderBadge',
  );

  return array('#type' => 'ajax', '#commands' => $commands);
}
