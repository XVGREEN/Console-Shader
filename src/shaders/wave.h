 namespace shaders{
    float  wave(vec2 fc ,double t) {
         auto rows = (double) ROWS;
         auto colls= (double) COLLS;
         vec2 uv;
         uv = (fc*2-vec2(colls,rows))/rows;
         uv.y = -uv.y;
         uv.y*=2.0;
         float out=0.0;
         
         if(sin(uv.x*5.0+t*4.0)*.3<uv.y){
         	out = 0.8;
         }
          
         return out;
     }

}


	
