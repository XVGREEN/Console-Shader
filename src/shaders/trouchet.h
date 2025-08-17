 namespace shaders{


	float hash21(vec2 p) {
	    vec2 v= vec2(12443.34, 345.45);
	    p.x*=v.x;
	    p.y*=v.y;
      	p = fract(p);
   	    p += dot(p, p + vec2(34.345));
  	    return fract(p.x * p.y);
	}

    float  trouchet(vec2 fc ,double t) {
         auto rows = (double) ROWS;
         auto colls= (double) COLLS;
         vec2 uv;
         uv = (fc*2.0-vec2(colls,rows))/rows;
         uv.y = -uv.y;
         uv.y*=2.0;
        uv*=1.5;
        vec2 i= floor(uv);
        vec2 g= fract(uv)-.5;
        if(hash21(i+floor(t*0.5))<.5)g.x=-g.x;
        float d= step((abs(abs(g.y-g.x)-.5)),.1);
          
                  
         return 1.- d;
     }

}


	
