 namespace shaders{


   float arrows  ( vec2 u,double time) {
       auto rows = (double) ROWS;
       auto colls= (double) COLLS;
       vec2 resolution(colls,rows);
       u*=.4;

       float O=0.0;  
       float h = 0.5;
       float t = time / 1.5;
       float x = fract(t) - h;
       float a = t + x - x * abs(x + x);
       float p = 5.0 / resolution.y;
   
       vec2 U = u * p;
       vec2 V;
       vec2 C = vec2(h, 0.25);
   
       int n = int(t) % 4;
       int i = -1;
   
       if (n % 2 == 1) {
           U.y += h;
           a += 2.0;
       }
   
       for (; i++ < 6; ) {

           vec2 offset = vec2(float(i % 3) - 1.0, float(i / 3));
           vec2 fractU = fract(n > 1 ? U + h : U);
 
   
           V = C + rot((fractU - offset - C),a*1.5708);   
           x = abs(V.x - h);
           t = V.y;
   
           O += (smoothstep(

              -p,p,
              fmin(
                   (t < h || x < 0.25) ? t : t - h,
                   t < h ? 0.25 - x : 1.0 - x - t
               )
           ));
       }
   
       if (n % 2 == 1) {
           O = 1. - O;
       }
       return O;
   }
   

 

}


	
