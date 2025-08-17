 namespace shaders{
    float  trig(vec2 fc ,double t) {
         auto rows = (double) ROWS;
         auto colls= (double) COLLS;
         vec2 uv;
         uv = (fc*2.0-vec2(colls,rows))/rows;
         uv.y = -uv.y;
         uv.y*=2.0;
        
       
         vec2 p = normalize(vec2(1.,1.));
         p=rot(p,t);
   
         vec2 lv= vec2(p.x,dot(p,vec2(0.,1.)));      
         vec2 lr= vec2(dot(p,vec2(1.,0.)),p.y); 
          
         float d = sdLine(uv,vec2(0.0,p.y), lr);  
         d = fmin(d,sdLine(uv,vec2(p.x,0.), lv));
         d= fmin(d,sdLine(uv,vec2(0),p));


     
       d= fmin(d,fabs(1.-(length(uv))));
       d += step(d,0.05);
       if(abs(uv.x)<0.05 || abs(uv.y)<0.05) d=0.0;
       d= clamp(d,0.0,1.0);
                  
         return 1.- d;
     }

}


	
