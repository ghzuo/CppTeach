Traj = function(){

    var iframe=0, nframe=0, natosm=0, duration=50, ndim, vplot=false, fplot=false, trace=false;
    var svgsize=550, offset=0.5*svgsize, circleSize=10, lenArrow=80;
    var cirColor=["#FF0000","#FF8800","#FFFF00","#88FF00", "#00FF00", "#00FF88", "#00FFFF","#0088FF","#0000FF", "#8800FF"];
    var txtColor=["#00FFFF","#008888","#0000FF","#8800FF", "#FF00FF", "#FF0088", "#FF0000","#FF8800","#FFFF00", "#88FF00"];
    var atoms, movie, traj;

    var svg = d3.select("#theSVG")
	.attr("height", svgsize)
	.attr("width", svgsize)
        .attr("xmlns", "http://www.w3.org/2000/svg");

    this.firstFrame = function(){moveToFrame(0);};
    this.lastFrame  = function(){moveToFrame(nframe-1);};
    this.nextFrame  = function(){if(iframe<nframe-1)moveToFrame(++iframe);};
    this.prevFrame  = function(){if(iframe>0) moveToFrame(--iframe);}
    this.stopMovie  = function(){movie=window.clearInterval(movie)};
    this.playMovie  = function(){movie=setInterval(singlePlay, duration);};
    this.loopMovie  = function(){movie=setInterval(loopPlay, duration);};

    this.init = function(json){
	traj = json;
	nframe = traj.frame.length;
	natom  = traj.frame[0].atom.length;
	ndim   = traj.frame[0].atom[0].length;
	if(ndim >= 4) vplot = true;
	if(ndim >= 6) fplot = true;

	var dmax=0;
	for(var i=0; i<nframe; ++i){
	    for(var j=0; j<natom; ++j){
		var p = traj.frame[i].atom[j].phase;
		dmax = Math.max(dmax, Math.abs(p[0]), Math.abs(p[1]));
	    }
	}

	dmax = (offset-circleSize/2)/dmax;
	for(var i=0; i<nframe; ++i){
	    for(var j=0; j<natom; ++j){
		var p = traj.frame[i].atom[j].phase;
		p[0] = p[0]*dmax + offset;
		p[1] = offset + circleSize - p[1]*dmax;
	    }
	}

	if(vplot){
	    var vmax=0;
	    for(var i=0; i<nframe; ++i){
		for(var j=0; j<natom; ++j){
		    var p = traj.frame[i].atom[j].phase;
		    vmax = Math.max(vmax, (p[2]*p[2]+p[3]*p[3]));
		}
	    }
	    vmax = vmax==0?0:lenArrow/Math.sqrt(vmax);

	    for(var i=0; i<nframe; ++i){
		for(var j=0; j<natom; ++j){
		    var p = traj.frame[i].atom[j].phase;
		    p[2] *= vmax; p[3] *= -vmax;

		}
	    }
	}

	if(fplot){
	    var fmax=0;
	    for(var i=0; i<nframe; ++i){
		for(var j=0; j<natom; ++j){
		    var p = traj.frame[i].atom[j].phase;
		    vmax = Math.max(vmax, (p[4]*p[4]+p[5]*p[5]));
		}
	    }
	    fmax = fmax==0?0:lenArrow/Math.sqrt(fmax);
	    for(var i=0; i<nframe; ++i){
		for(var j=0; j<natom; ++j){
		    var p = traj.frame[i].atom[j].phase;
		    p[4] *= fmax; p[5] *= -fmax;
		}
	    }
	}

	for(var i=0; i<natom; ++i){
	    var theAtom  = traj.frame[iframe].atom[i];
	    var thePoint = svg.append("g").attr("class", "atom")
		.attr("transform", project(theAtom));
	    thePoint.append("polyline").attr("class", "V").attr("points", vProject(theAtom))
		.attr("marker-end", "url(#markerV)").style("stroke", "red");
	    thePoint.append("polyline").attr("class", "F").attr("points", vProject(theAtom))
		.attr("marker-end", "url(#markerF)").style("stroke", "blue");
	    thePoint.append("circle").attr("r",circleSize)
		.style("fill",cirColor[i]);
	    thePoint.append("text").attr("text-anchor", "middle").attr("dy",4)
		.text(i).style("stroke",txtColor[i]).style("fill",txtColor[i]);
	}

	atoms = svg.selectAll("g.atom");
	return this;
    };

    function singlePlay(){
	if(iframe == nframe)
            stopMovie();

        ++ iframe;
	moveToFrame(iframe);
    };

    function loopPlay(){
	++ iframe;
	if(iframe == nframe)
	    iframe = 0;
	moveToFrame(iframe);
    };

    function moveToFrame(n){
	iframe = n;
	d3.select("#iframe").attr("value", iframe);

	atoms.data(traj.frame[n].atom);
        if(vplot)
	    atoms.select("polyline.V").attr("points",vProject);
        if(fplot)
	    atoms.select("polyline.F").attr("points",fProject);
	atoms.transition().duration(duration)
	    .attr("transform", project);
    }

    function project(d){
	return "translate(" + d.phase[0] + "," + d.phase[1] + ")";
    }

    function vProject(d){
	return "0,0 " + d.phase[2] + "," + d.phase[3];
    }

    function fProject(d){
	return "0,0 " + d.phase[4] + "," + d.phase[5];
    }
}

   // <line x1="0" y1="0" x2="200" y2="50" fill="red" stroke-width=2 stroke="red"
   // marker-end="url(#markerArrow)" /> 
   // <line x1="0" y1="0" x2="500" y2="80"  style="stroke:red;stroke-width:2;fill:red" marker-end="url(#markerArrow)" />e
