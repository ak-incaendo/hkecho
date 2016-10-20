<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * function to send category and department list
 * @param type $arg
 * @return type
 */
function _get_details($arg) {
  $return['category'] = _get_array('category');
  $return['departments'] = _get_array('departments');
  return ($return);
}

/**
 * function to load category and department taxonomy
 * @param type $name
 * @return type
 */
function _get_array($name) {
  $vid = taxonomy_vocabulary_machine_name_load($name);
  $tree = taxonomy_get_tree($vid->vid);
  foreach($tree as $item) {
    $data[$item->tid] = $item->name;
  }
  return $data;
}

/**
 * function to save node through post data
 * @param type $data
 * @return int
 */
function _insert_data($data) {
  $node = new stdClass();
  $node->type = 'echo';
  node_object_prepare($node);
  $node->uid = 0;
  $node->title  = $data['title'];
  $node->language = LANGUAGE_NONE;
  $node->body[$node->language][0]['value']   = !empty($data['desc']) ? $data['desc'] : null;
  $node->field_category[$node->language][0]['tid'] = !empty($data['category_id']) ? $data['category_id'] : null;
  $node->field_department[$node->language][0]['tid'] = !empty($data['department_id']) ? $data['department_id'] : 17;
  $node->field_image_path[$node->language][0]['tid'] =  !empty($data['image_url']) ? $data['image_url'] : null;

  $node = node_submit($node);
  try {
     node_save($node);
     $msg = 1;
  }
  catch (Exception $e) {
    print $e;
    $msg = 0;
  }
  return $msg;
}

/**
 * function to save hktweets
 */
function _save_tweet($tweet) {
  $node = new stdClass();
  $node->type = 'hk_tweet';
  node_object_prepare($node);
  $node->uid = 0;
  $node->title  = $tweet['title'];
  $node->language = LANGUAGE_NONE;
  $node->field_name['und'][0]['value'] = $tweet['Name'];
  //p($node);
  $node = node_submit($node);
  try {
     node_save($node);
     $msg = 1;
  }
  catch (Exception $e) {
    print $e;
    $msg = 0;
  }
  return $msg;
}