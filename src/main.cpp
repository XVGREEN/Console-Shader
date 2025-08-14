#include <cmath>
#include <iostream>
#include <string>
#define PI  3.1415
#define ROWS 80
#define COLLS 40
#define GRIDSIZE ROWS*COLLS
#define SPEED (16.0/10000.0)

char shader(int x,int y,double t);
void render(std::string& buffer,double t) ;
void render(char buffer[],double t) ;
int main() {
    double time = 0;
    int frames =0;
    using namespace std;
    string buffer;
    while (frames <10000000) {
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



