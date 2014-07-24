#ifndef _OF_PEN
#define _OF_PEN

#define numsands 10

#include "ofMain.h"
#include "sandPainter.h"
class pen{
    
public:
    
    //  stroke
    int centx;
    int centy;
    float vx;
    float vy;
    float tinc;
    int identify;
    int pal;
    
    int waitCnt;
    int step;
    
    int time;
    bool flag_d;
    //    bool setDirection;
    
    
    //  colors
    bool setEraser;
    int r;
    int g;
    int b;
    bool flag_c;
    int a;
    int waiting;
    
    
    //  functions
    pen();
    void setup();
    void update();
    void draw();
    void setR(int red);
    void setG(int green);
    void setB(int blue);
    void setID(int ID);
    
    /*
     int maxcon;
     int numcon;
     int connections[100];
     void connectTo(int f);
     bool friendOf(int x);
     */
    
    sandPainter sands;
    
};

#endif
