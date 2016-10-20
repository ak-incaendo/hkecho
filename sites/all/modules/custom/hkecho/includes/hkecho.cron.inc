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
  $query = db_insert('user_information')->fields(array('name', 'birth_date', 'joining_date','department','created'));
  foreach($dates as $detail) {
    $query->values(array(
        'name' => $detail->name,
        'birth_date' => $detail->birthdate,
        'joining_date' => $detail->joiningDate,
        'department' => $detail->department,
        'created' => time()
      )
    );
  }
  $result = $query->execute();
}