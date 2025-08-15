#include "vmath.h"
char  shader(vec2 fc ,double t) {
   auto rows = (double) ROWS;
   auto colls= (double) COLLS;
   vec2 uv;   
   uv.x  = (fc.x*2.0-colls)/rows;
   uv.y = (fc.y*2.0-rows)/rows;
   uv.y = -uv.y;
   uv.y*=2.0;
   uv.y+=.5;
   auto gv = fract(uv);
   gv.x-=0.5;
   gv.y-=0.5;  
  // gv= scale(uv) 
   char out=' ';
   double  inc= fabs(sin(t*10.0))*0.6; 
   if (sdHeart(scale(gv,2.0+inc))<0.0) {
      out='@';
   }
   

  
    return out;
}

