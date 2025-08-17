#include <cmath>
#include <iostream>
#include <stdint.h>
#include <wchar.h>
#include <stdio.h>

#define PI  3.1415
#define ROWS 60
#define COLLS 100
#include "include//vmath.h"
#include "shaders//shaders.h"

void render (float t,int mode);
wchar_t buffer [ROWS][COLLS];
float  (*shader)(vec2,double);  // assign to your custom shader function
void change_shader(double t);

int main() {
    //init clock
    auto start = std::chrono::high_resolution_clock::now(); //start clock
    auto now = std::chrono::high_resolution_clock::now();  //end time
    double time;    

    shader = shaders::birth;
    auto range = shaders::range::contrast; //value range
    int frame=0;
    printf("\033[2J");

    while (true) {   
        now = std::chrono::high_resolution_clock::now(); 
        time = std::chrono::duration<double>(now - start).count();    
        if(frame%5==0){
     	   render(time,range); 
     	   change_shader(time); 
  	       buffer[ROWS-1][COLLS-1] =L'\0';
     	   printf("\033[H");
	       wprintf(L"%ls\n", buffer);
        }
        usleep(16);
        frame++; 
        if(frame==100000)frame=0;   
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


void change_shader(double t) {
	shader= shaders::birth;
    t= fmod(t,32.0);
	if(t>=8.0){
		shader= shaders::trouchet;
	}
	if(t>=16){
		shader = shaders::trig;		
	}
	if(t>=24){
		shader= shaders::arrows;
	}
	
		
}
