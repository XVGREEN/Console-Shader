namespace shaders {
	char values_smooth[] = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@";
	char values_medium[] = " .:-=+*#%@";
	char values_contrast[] = ".oO@";	
	const wchar_t values_box[] =L" ░▒▓█";
	enum range  {contrast,medium,smooth,box};
	wchar_t get_char(double val,int mode){
       switch(mode){                                                        
            case range::contrast:{
             	 int index = (int)(val * 4);
                 return shaders::values_contrast[index];
       	     }
            case  range::medium:{
                  int index = (int)(val * 8);                                        
                  return shaders::values_medium[index];    
             }
            case range::smooth:{
         		   int index = (int)(val * 69);
           		   return shaders::values_smooth[index];
            }
            case range::box:{
        		    int index = (int)(val *4);
                    return shaders::values_box[index];
             }
        }
        return 0;
     }

}

//#include "bouncing.h"
#include "circle.h"
#include "boxworld.h"
//#include "heart.h"


   
  
