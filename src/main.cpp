#include <cmath>
#include <iostream>
#include <string>
#include "vmath.h"
#define PI  3.1415
#define ROWS 80
#define COLLS 40
#define GRIDSIZE ROWS*COLLS
#define SPEED (16.0/500.0)
#include "shaders.h"

char shader(int x,int y,double t);
void render(std::string& buffer,double t) ;
void render(char buffer[],double t) ;
int main() {
    double time = 0;
    int frames =0;
    using namespace std;
    string buffer;
    while (frames <1000) {
        buffer.clear();
        render(buffer,time);
        cout<<buffer<<endl;
        system("clear");
        time+=SPEED;
        frames+=1;
    }
}
// i dont like this approach, might remove division later
 void render(std::string &buffer,double t) {
    for (int i= 0;i<GRIDSIZE;i++) {
        int  x =i%ROWS;
        int  y = i/COLLS;
        buffer.push_back(shader(x,y,t));
        if(x%ROWS==0) buffer+="\n";
    }
 }






