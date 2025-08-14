
 char shader(int x,int y,double t) {
   auto rows = (double) ROWS;
   auto colls= (double) COLLS;
   double uvx = (x*2.0-colls)/colls;
   double uvy= (y*2.0-rows)/colls;
    uvy = -uvy;
     uvx-=0.9;

    double d = uvx*uvx+uvy*uvy;
   if (d<1.2) {
       if (sin(uvx*2.0+t*10.0)*0.4<uvy) {
          return ' ';
        }
      return '@';
  }
    return '.';
}

