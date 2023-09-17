<?php
    $requestReason = $_GET['RequestReason'];
    $carNumber = $_GET['CarNumber'];
    $carSpeed =  $_GET['CarSpeed'];
    $flowSpeed = $_GET['FlowSpeed'];
    $fineAmmount = $_GET['FineAmmount'];

    $mysqli = new mysqli('127.0.0.1', 'soamane47_base', 'PLy9jN%C', 'soamane47_base');

    switch($requestReason)
    {
        case 0:
            $sql_query = $mysqli->query( "INSERT INTO `Speed`(`CarNumber`, `CarSpeed`, `FlowSpeed`, `FineAmmount`) VALUES ('$carNumber', '$carSpeed', '$flowSpeed', '$fineAmmount' )" );
            break;
        
        case 1:
            $sql_query = $mysqli->query( "INSERT INTO `Seatbelt`(`CarNumber`, `FineAmmount`) VALUES ('$carNumber', '$fineAmmount' )" );
            break;
        
        case 2:
            $sql_query = $mysqli->query( "DELETE FROM `Speed` WHERE `CarNumber` = '$carNumber'" );
            break;

        case 3:
            $sql_query = $mysqli->query( "DELETE FROM `Seatbelt` WHERE `CarNumber` = '$carNumber'" );
            break;
    }
?>