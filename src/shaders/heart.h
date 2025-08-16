namespace shaders{
   
     wchar_t heart(vec2 fc ,double t,int mode) {
        auto rows = (double) ROWS;
        auto colls= (double) COLLS;
        vec2 uv;
        uv.x  = (fc.x*2.0-colls)/rows;
        uv.y = (fc.y*2.0-rows)/rows;
        uv.y = -uv.y;
        uv.y*=2.0;
        uv.y+=.3;
       uv= scale(uv,1-jump(fract(t*12.0))*.3);
       wchar_t out =' ';
        if (sdHeart(uv)<0.0) {
             out='@';
        }
          return out;
     }
    
}
