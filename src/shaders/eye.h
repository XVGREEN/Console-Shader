 namespace shaders{
    float  eye (vec2 fc ,double t) {
         auto rows = (double) ROWS;
         auto colls= (double) COLLS;
         vec2 uv;
         uv = (fc*2.0-vec2(colls,rows))/rows;
         uv.y = -uv.y;
         uv.y*=2.0;
         float out=0.0;
         
         out = abs(sdCircle(uv,0.7+0.5*jump(fract(t)))-0.2);
         out = step(out,0.1);
         
          
         return out;
     }

}


	
