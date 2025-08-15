namespace shaders{
	char  circle(vec2 fc ,double t) {
		auto rows = (double) ROWS;
 	    auto colls= (double) COLLS;
	    vec2 uv;   
	    uv.x  = (fc.x*2.0-colls)/rows;
 	    uv.y = (fc.y*2.0-rows)/rows;
 	    
        uv.y = -uv.y;
        uv.y*=2.0;
      //  uv.y+=.5;
        char out =' ';
        if (sin(length(uv)*3.0+t*40.0)<0.0) {
      		 out='@';
         } 
         return out;
	}

}
