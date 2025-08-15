#include <cmath>
#include <iostream>
#include <stdint.h>
#include <unistd.h>
#define PI  3.1415
#define ROWS 60
#define COLLS 100
#define GRIDSIZE ROWS*COLLS
#define SPEED 5e-2
#include "include//vmath.h"
#include "shaders//bouncing.h"

void render (float t);
char buffer [ROWS][COLLS];
int main() {
    double time = 0;
    uint32_t frames =0;
    while (frames <1000) {        
        render(time);   
        buffer[ROWS-1][COLLS-1] = '\0';
        printf("\033[H"); 
        printf("%s",buffer);
        usleep(40000);   
        time+=SPEED;
        frames+=1;
       
    }
}

 void render(float t) {
    for(uint8_t y=0;y<ROWS;y++){
		for(uint8_t x=0;x<COLLS;x++){
		    vec2 fc{float(x),float(y)};
			buffer[y][x]=shaders::bouncing_ball(fc,t);
		}  
		buffer[y][COLLS-1]='\n';
    }
 }
