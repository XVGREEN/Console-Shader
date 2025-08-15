#include <cmath>
#include <iostream>
#include <string>
#include <stdint.h>
#include <unistd.h>
#define PI  3.1415
#define ROWS 60
#define COLLS 100
#define GRIDSIZE ROWS*COLLS
#define SPEED 1e-2
#include "include//vmath.h"
#include "shaders//circle.h"

void render (float t);
char buffer [ROWS][COLLS];
int main() {
    double time = 0;
    uint32_t frames =0;
    char  img[GRIDSIZE];
    while (frames <1000) {        
        render(time);
        memcpy(img,buffer,GRIDSIZE);
        img[GRIDSIZE - 1] = '\0';
        std:: cout<<img<<std::endl;
        usleep(70000);   
        time+=SPEED;
        frames+=1;
       
    }
}

 void render(float t) {
    for(uint8_t y=0;y<ROWS;y++){
		for(uint8_t x=0;x<COLLS;x++){
		    vec2 fc{float(x),float(y)};
			buffer[y][x]=shaders::circle(fc,t);
		}  
		buffer[y][COLLS-1]='\n';
    }
 }
