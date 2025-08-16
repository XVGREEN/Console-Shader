namespace shaders{
	float  circle(vec2 fc ,double t) {
		auto rows = (double) ROWS;
 	    auto colls= (double) COLLS;
	    vec2 uv;   
	    uv = (fc*2.0-vec2(colls,rows))/rows; 	    
        uv.y = -uv.y;
        uv.y*=2.0;
        return  abs(sin(length(uv)+t));
       
	}

}
