BarPlot = function(){
    var svgSize = [550, 550];
    var margin  = {top:30, right:20, bottom:30, left:80}; 
    var width   = svgSize[0] - margin.left - margin.right;
    var height  = svgSize[1] - margin.top  - margin.bottom;

    this.init = function(json){

	var data = json.point;

	var xScale = d3.scale.linear().range([0, width])
	    .domain([0, d3.max(data,function(d){return d.number;})]);
	var yScale = d3.scale.linear().range([height, 0])
	    .domain([0,data.length]);

	var xAxis = d3.svg.axis().scale(xScale)
	    .orient("bottom").ticks(5); 

	var svg = d3.select("#theSVG")
	    .attr("width", svgSize[0])
	    .attr("height", svgSize[1]);

	var barWidth = height/data.length;
          
        var enterBar = svg.selectAll("rect").data(data).enter();
	
	enterBar.append("rect").attr("x",margin.left)  
            .attr("y",function(d,i){return yScale(i)+margin.top-barWidth;})  
            .attr("width",function(d){return xScale(d.number);})
            .attr("height",barWidth*0.95)
            .attr("fill","red");

	enterBar.append("text").attr("class", "axis")
	    .attr("x",margin.left-10)  
            .attr("y",function(d,i){return yScale(i)+margin.top-0.45*barWidth;})
	    .attr("text-anchor", "end")
	    .text(function(d){return d.name;});

	svg.append("g").attr("class", "x axis")
	    .attr("transform", "translate(" + margin.left + "," + (margin.top+height) + ")") 
	    .call(xAxis);
    };
}
