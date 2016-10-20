<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function _get_details($arg) {
  $return['category'] = _get_array('category');
  $return['departments'] = _get_array('departments');
  return ($return);
}

function _get_array($name) {
  $vid = taxonomy_vocabulary_machine_name_load($name);
  $tree = taxonomy_get_tree($vid->vid);
  foreach($tree as $item) {
    $data[$item->tid] = $item->name;
  }
  return $data;
}