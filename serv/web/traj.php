<!DOCTYPE html>
<html>
   <head>
   <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
   <title>Trajectory</title>
     <script type="text/javascript" src="d3.js"></script>
     <script type="text/javascript" src="traj.js"></script>
   <link rel="stylesheet" href="page.css" type="text/css" />
   </head>
   <body>
   <div class="page">
   <div class="viewer">
   <table align="center"><tr><td align="left"><h1>Trajectory Displayer</h1></td></tr><tr><td>
   <table align="center" class="viewer"><tr class="player">
   <td><div id="chart"><svg id="theSVG" height="550", width="550">
   <defs>
   <marker id="markerV" markerWidth="10" markerHeight="10" refx="4" refy="5" 
   fill="red" orient="auto" >
   <path d="M1,2 L4,5, L1,8 L10,5 Z" />
   </marker>
   <marker id="markerF" markerWidth="10" markerHeight="10" refx="4" refy="5" 
   fill="blue" orient="auto">
   <path d="M1,2 L4,5, L1,8 L10,5 Z" />
   </marker>
   </defs>
   </svg></div></td>
   <td>
   <form action="traj.php" method="post" enctype="multipart/form-data">
   <input id="upfile" type="file" name="file" style="display:none" onchange="document.getElementById('submit').click()" /> 
   <input type="submit" name="submit" id="submit" value="Submit" style="display:none" />
   </form>
   <input type="button" value="Open"  onclick="document.getElementById('upfile').click()" /> <br/>
   <input type="button" class="uninit" value="First" onclick="aTraj.firstFrame()" /><br />
   <input type="button" class="uninit" value="Prev"  onclick="aTraj.prevFrame()" /><br />
   <input type="button" class="uninit" value="Play"  onclick="aTraj.playMovie()" /><br />
   <input type="button" class="uninit" value="Stop"  onclick="aTraj.stopMovie()" /><br />
   <input type="button" class="uninit" value="Next"  onclick="aTraj.nextFrame()" /><br />
   <input type="button" class="uninit" value="Last"  onclick="aTraj.lastFrame()" /><br />
   <input type="text"   class="uninit" value="0" id='iframe' readonly="readonly" /><br />
   </td></tr></table>
   </td></tr></table>
   </div></div>
   <?php
   $traj = "";
   if($_POST['submit'] == "Submit"){
     if($_FILES["file"]["size"] > 2000000){
       echo "File size is too big!";
     }else{
       if($_FILES["file"]["error"] > 0){
         echo "Return Code: " . $_FILES["file"]["error"] . "<br />";
       }else{
         $lines = file($_FILES["file"]["tmp_name"]);
         $items = preg_split("/[\s,]+/", trim($lines[0]));
         $nframe = $items[0];
         $traj  = '{"frame":[';
         $frame = array(); 
         foreach($lines as $line){
	   $line = ltrim($line);
	   if($line != ""){
	     $items = preg_split("/[\s,]+/", $line);
	     foreach($items as $item){ $item = trim($item);}
	     $iframe = array_shift($items);
	     $iatom  = array_shift($items);
	     $phase = '{"phase":[' . implode(',', $items) . ']}';
	     if($iframe != $nframe){
	       $traj = $traj . '{"atom":[' . implode(',', $frame) . ']},';
	       $nframe = $iframe;
	       $frame = array();
	     }
	     array_push($frame,$phase);
	   }
         }
         $traj = $traj . '{"atom":[' . implode(',', $frame) . ']}]}';
       }
     }
   }
   ?>
   </body>
   <script type="text/javascript">
    window.onload = function(){
      aTraj = new Traj();
      <?php 
      if($traj != ""){
	echo 'aTraj.init('. $traj .');';
      }else{
	echo 'd3.selectAll("input.uninit").attr("disabled","disabled");';
      }?>
    }
   </script>
</html>
