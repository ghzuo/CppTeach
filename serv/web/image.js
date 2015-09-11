ImagePlot = function(){
    var svgSize = [550, 550];
    var margin  = {top:40, right:40, bottom:40, left:40}; 
    var width   = svgSize[0] - margin.left - margin.right;
    var height  = svgSize[1] - margin.top  - margin.bottom;
    var zcolor  = ["#FF0000","#FF8800","#FFFF00","#88FF00", "#00FF00", "#00FF88", "#00FFFF","#0088FF","#0000FF"];

    this.init = function(json){

	var data  = json.point;
	var xrang = d3.extent(data,function(d){return d.x;})
	var yrang = d3.extent(data,function(d){return d.x;})
	var ncell = [(xrang[1]-xrang[0]+1), (yrang[1]-yrang[0]+1)]
	var cell  = [width/ncell[0], height/ncell[1]];

	var xScale = d3.scale.linear().range([0, (width-cell[0])]).domain(xrang);
	var yScale = d3.scale.linear().range([(height-cell[1]), 0]).domain(yrang);
	var zScale = d3.scale.linear().range([0, zcolor.length-1])
	    .domain(d3.extent(data,function(d){return d.z;}));

	var xAxis = d3.svg.axis().scale(xScale)
	    .orient("bottom").ticks(5); 
	var yAxis = d3.svg.axis().scale(yScale)
	    .orient("left").ticks(5);
	var x2Axis = d3.svg.axis().scale(xScale)
	    .orient("top").ticks(5); 
	var y2Axis = d3.svg.axis().scale(yScale)
	    .orient("right").ticks(5);


	var svg = d3.select("#theSVG")
	    .attr("width", svgSize[0])
	    .attr("height", svgSize[1]);

	var enterBar = svg.selectAll("rect").data(data).enter();
	
	enterBar.append("rect")
	    .attr("x",function(d){return margin.left+xScale(d.x);})  
            .attr("y",function(d){return margin.top +yScale(d.y);})  
            .attr("width", cell[0])
            .attr("height",cell[1])
            .attr("fill",function(d){return zcolor[Math.floor(zScale(d.z))]});

	svg.append("g").attr("class", "x axis")
	    .attr("transform", "translate("+(margin.left+0.5*cell[1])+","+(margin.top+height)+")") 
	    .call(xAxis);
	svg.append("g").attr("class", "x axis")
	    .attr("transform", "translate(" +(margin.left+0.5*cell[1])+ "," + margin.top + ")") 
	    .call(x2Axis);
	svg.append("g")
	    .attr("class", "y axis")
	    .attr("transform", "translate("+margin.left + "," + (margin.top+0.5*cell[1]) + ")") 
	    .call(yAxis);
	svg.append("g")
	    .attr("class", "y axis")
	    .attr("transform", "translate("+(margin.left+width)+","+(margin.top+0.5*cell[1])+")") 
	    .call(y2Axis);

    };
}
