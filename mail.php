<?php
    if (isset($_POST["email"])) {
        $to_email = "contact@yathinbabu.com"; // change it
        $name = $_POST["firstname"];
        $from_email = $_POST["email"];
        $number = $_POST["phone"];
        $subject = "Book the wedding hall.";
        $body = $_POST["message"];
        $headers = "MIME-Version: 1.0" . "\r\n";
        $headers .= "Content-type:text/html;charset=UTF-8" . "\r\n";

        $headers .= 'From: <'.$from_email.'>' . "\r\n";
     
        if ( mail($to_email, $subject, $body, $headers)) {
          echo("Email successfully sent to $to_email...");
        } else {
          echo("Email sending failed...");
        }
      }
?>
