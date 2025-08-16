namespace shaders{
	char  circle(vec2 fc ,double t) {
		auto rows = (double) ROWS;
 	    auto colls= (double) COLLS;
	    vec2 uv;   
	    uv.x  = (fc.x*2.0-colls)/rows;
 	    uv.y = (fc.y*2.0-rows)/rows;
 	    
        uv.y = -uv.y;
        uv.y*=2.0;
        float d = abs(sin(length(uv)+t*20.0));
        char out = values_smooth[(int)(d*69)];
      
         return out;
	}

}
