<!DOCTYPE html>
<html>
<head>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
<script>
$(document).ready(function(){
  $("form").submit(function(){
    alert("Submitted");
  });
});
</script>
</head>
<body>

<form action="">
  First name: <input type="text" name="FirstName" value="Virat"><br>
  Last name: <input type="text" name="LastName" value="Kohli"><br>
  <input type="submit" value="Submit">
</form> 

</body>
</html>
