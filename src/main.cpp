#include <cmath>
#include <iostream>
#include <stdint.h>
#include <unistd.h>
#include <wchar.h>
 #include <stdio.h>
#define PI  3.1415
#define ROWS 60
#define COLLS 100
#include "include//vmath.h"
#include "shaders//shaders.h"

void render (float t,int mode);
wchar_t buffer [ROWS][COLLS];
float  (*shader)(vec2 v,double);  // assign to your custom shader function

int main() {
    //init clock
    auto start = std::chrono::high_resolution_clock::now(); //start clock
    auto now = std::chrono::high_resolution_clock::now();  //end time
    double time;    
    shader = shaders::box_world;
    auto  range = shaders::range::contrast; //value range
    
    printf("\033[2J");
    while (true) {   
        now = std::chrono::high_resolution_clock::now(); 
        time = std::chrono::duration<double>(now - start).count();    
          
        render(time,range);   
        buffer[ROWS-1][COLLS-1] =L'\0';
		printf("\033[H");
		wprintf(L"%ls\n", buffer);
        usleep(16);   
    }
}

void render(float t,int mode) {
    for(uint8_t y=0;y<ROWS;y++){
		for(uint8_t x=0;x<COLLS;x++){
		    vec2 fc{float(x),float(y)};
			buffer[y][x]=shaders::get_char(shader(fc,t),mode);
		}  
		buffer[y][COLLS-1]=L'\n';
    }
 }

