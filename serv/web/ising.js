Traj = function(){

    var iframe=0, nframe, duration=50, svgSize = 550;
    var ndim, traj, movie;
    var scolor = {"-1":"blue", "1":"red"};
    var svg = d3.select("#theSVG")
	.attr("height", svgSize)
	.attr("width", svgSize);

    this.firstFrame = function(){moveToFrame(0);};
    this.lastFrame  = function(){moveToFrame(nframe-1);};
    this.nextFrame  = function(){if(iframe<nframe-1)moveToFrame(++iframe);};
    this.prevFrame  = function(){if(iframe>0)moveToFrame(--iframe);};
    this.stopMovie  = function(){movie = window.clearInterval(movie)};
    this.playMovie  = function(){movie=setInterval(loopPlay, duration);};

    this.init = function(json){
	traj = json;
	nframe = traj.frame.length;

	// set the 1~N state
	for(var i=1; i<nframe; ++i){
	    traj.frame[i].state = {};
	    for(var key in traj.frame[i-1].state)
	    	traj.frame[i].state[key]=traj.frame[i-1].state[key]+0;
	    for(var key in traj.frame[i].change)
		traj.frame[i].state[key] = traj.frame[i].change[key];
	}

	// ..
	var state = traj.frame[0].state;

	// get the cell size
	var maxindex=[0,0];
	for(var key in state){
	    var index = key.match(/\d+/g);
	    maxindex[0] = maxindex[0]<index[0]?index[0]:maxindex[0];
	    maxindex[1] = maxindex[1]<index[1]?index[1]:maxindex[1];
	}
	var cellsize = [svgSize/(parseInt(maxindex[0])+1), 
			svgSize/(parseInt(maxindex[1])+1)];

	// init the graphe
	for(var key in state){
	    var index = key.match(/\d+/g);
	    svg.append("rect")
		.attr("id", "cell"+key)
		.attr("x",index[0]*cellsize[0])
		.attr("y",index[1]*cellsize[1])
		.attr("width", cellsize[0])
		.attr("height",cellsize[1])
		.attr("fill",scolor[state[key]]);
	}

	return this;
    };

    function moveToFrame(n){
	iframe = n;
	d3.select("#iframe").attr("value", iframe);

	var state = traj.frame[iframe].state;
	for(var key in state){
	    svg.select("#cell"+key).attr("fill",scolor[state[key]]);
	}

	d3.selectAll("rect").style("border-width",0);
	var chg = traj.frame[iframe].change;
	for(var key in chg){
	    svg.select("#cell"+key)
		.style("border-width",1);
	}
    }

    function loopPlay(){
	++ iframe;
	if(iframe == nframe)
	    iframe = 0;
	moveToFrame(iframe);
    };
}
