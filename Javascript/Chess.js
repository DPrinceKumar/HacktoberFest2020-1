<DOCTYPE html>
<html>
<head>
<style>

div
{
border:1px solid black;
width:20px;
height:20px;
}

</style>
</head>
<body>
<script type="text/javascript">
    // create a chess table 8x8.

    var count = 0;

while (count < 64)
    {

    if (count % 2 == 0)

        {

        if (count % 8 == 0 && count !=0)
            {
            document.write('<br/><div style="background-color:#000000;float:left;">&nbsp</div>');

            }
        else    
            {
            document.write('<div style="background-color:#000000;float:left;">&nbsp</div>');    
            }
        }

    else

        {
        document.write('<div style="background-color:#FFFFFF;float:left;">&nbsp</div>');
        }
         /*  
    */          
    count++;
    }
</script>

</body>
</html>
