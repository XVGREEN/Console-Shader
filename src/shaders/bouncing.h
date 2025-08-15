namespace shaders{
    char  bouncing_ball(vec2 fc ,double t) {
         auto rows = (double) ROWS;
         auto colls= (double) COLLS;
         vec2 uv;
         uv.x  = (fc.x*2.0-colls)/rows;
         uv.y = (fc.y*2.0-rows)/rows;
         uv.y = -uv.y;
         uv.y*=2.0;
         
         vec2 c=uv;
         c.y-=.5;
         c.y-=jump(fract(t));
         float d = sdCircle(c,.7);
         char out =' ';
         if (d<0.0) {
             out='@';
             if(sin(c.x*3.0)*.4<c.y){
             	out = '.';
             }
         }
         	
         if(uv.y<0.0){
         	out='-';
         }
         return out;
     }

}


	
