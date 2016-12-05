<?php
$count_number = isset($argv[1]) ? (int)$argv[1] : 1;

function fibonacci_pure($n){
  $a = 0;
  $b = 1;

  for ($i = 0; $i < $n; $i++){
    $sum = $a+$b;
    $a = $b;
    $b = $sum;
  }

  return $a;
}

print fibonacci_pure($count_number).PHP_EOL;

print fibonacci($count_number).PHP_EOL;
