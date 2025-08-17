 namespace shaders{
    float  birth(vec2 fc ,double t) {
         auto rows = (double) ROWS;
         auto colls= (double) COLLS;
         vec2 uv;
         uv = (fc*2.0-vec2(colls,rows))/rows;
         uv.y = -uv.y;
         uv.y*=2.0;
        
       
         uv*=1.5;
         uv.x+=sin(floor(uv.y*2.));
         uv.y= fract(uv.y)-.5;
         uv.y+=.2;  
         float f= sin(uv.x*5.0+t*5.)*.1;
         float d = (abs(uv.y-f));
         if(abs(uv.x)>.8)d=1.0;
         d = fmin(d,length(uv-vec2(.8,f))-0.2);
         d= step(d,0.08);
                  
         return 1.- d;
     }

}


	
