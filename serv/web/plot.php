<!DOCTYPE html>
<html>
   <head>
   <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
   <title>Line Plotter</title>
   <script type="text/javascript" src="d3.js"></script>
   <script type="text/javascript" src="lineplot.js"></script>
   <link rel="stylesheet" href="page.css" type="text/css" />
   </head>
   <body>
   <div class="viewer">
   <table class="button" align="center"><tr><td align="left">
   <h1>Line Ploter</h1>
   </td><td align="right" valign="bottom">
   <button onclick="document.getElementById('upfile').click()" id="open">Open</button>
   </td></tr><tr><td colspan="2">
   <div id="chart"><svg id="theSVG"></svg></div>
   </td></tr></table>

   <form action="plot.php" method="post" enctype="multipart/form-data">
   <input id="upfile" type="file" name="file" style="display:none" onchange="document.getElementById('submit').click()" /> 
   <input type="submit" name="submit" id="submit" value="Submit" style="display:none" />
   </form>
   </div>
</body>
<script type="text/javascript">
  window.onload = function(){
     var aPlot = new LinePlot();
  <?php
  if($_POST['submit'] == "Submit"){
    if($_FILES["file"]["size"] > 2000000){
      echo "File size is too big!";
    }else{
      if($_FILES["file"]["error"] > 0){
	echo "Return Code: " . $_FILES["file"]["error"] . "<br />";
      }else{
	$lines = file($_FILES["file"]["tmp_name"]);
	$points = array();
	foreach($lines as $line){
	  $line = trim($line);
	  if($line != ""){
	    $items = preg_split("/[\s,]+/", $line);
	    foreach($items as $item){$item = trim($item);}
	    $aPoint = '{"x":' . $items[0] . ',' . '"y":' . $items[1] . '}';
	    array_push($points, $aPoint);
	  }
	}
	$data  = '{"point":[' . join(',', $points) . ']}';
	echo 'aPlot.init('. $data .');' . "\n";
      }
    }
  }
     ?>}
</script>
</html>