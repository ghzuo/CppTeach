LinePlot = function(){
    var svgSize = [550, 550];
    var margin  = {top:30, right:20, bottom:30, left:50}; 
    var width   = svgSize[0] - margin.left - margin.right;
    var height  = svgSize[1] - margin.top  - margin.bottom;

    this.init = function(json){

	var data = json.point;

	var xScale = d3.scale.linear().range([0, width])
	    .domain(d3.extent(data,function(d){return d.x;}));
	var yScale = d3.scale.linear().range([height, 0])
	    .domain(d3.extent(data,function(d){return d.y;}));

	var xAxis = d3.svg.axis().scale(xScale)
	    .orient("bottom").ticks(5); 
	var yAxis = d3.svg.axis().scale(yScale)
	    .orient("left").ticks(5);
	var theline = d3.svg.line()
	    .x(function(d){return xScale(d.x);}) 
	    .y(function(d){return yScale(d.y);});

	var svg = d3.select("#theSVG")
	    .attr("width", svgSize[0])
	    .attr("height", svgSize[1]);

	svg.append("path").attr("class", "plot").attr("d", theline(data))
	    .attr("transform", "translate(" + margin.left + "," + margin.top + ")");


	svg.append("g").attr("class", "x axis")
	    .attr("transform", "translate(" + margin.left + "," + (margin.top+height) + ")") 
	    .call(xAxis);

	svg.append("g")
	    .attr("class", "y axis")
	    .attr("transform", "translate(" + margin.left + "," + margin.top + ")") 
	    .call(yAxis);
    };
}
