<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function hkecho_save_dates() {
  $result = drupal_http_request(url('http://192.168.90.233:8080/hrms/birthday'));
  $dates = json_decode($result->data);
  $values = '';
  foreach($dates as $detail) {
    $values .= '('.$detail->name .','. $detail->birthdate.','. $detail->joiningDate .','. $detail->department .','. time().')';
    $values .= ',';
  }
  $query = db_query('INSERT INTO {user_information} (name, birth_date, joining_date,department,created VALUES
  '.$values);
  $result = $query->execute();
  p($result);
}