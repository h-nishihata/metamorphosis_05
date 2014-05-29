#ifndef _OF_PEN
#define _OF_PEN

#define numsands 10

#include "ofMain.h"
#include "sandPainter.h"
class pen{
    
public:
    float t;
    float tv;
    int pal;
    int centx;
    int centy;
    float vx;
    float vy;
    float tinc;
    int identify;
    
    int waitCnt;
    int step;

    int time;
    bool flag_f;
    bool flag_t;

    float rad;
//    float radiusNoise;
//    float thisRadius;
//    float radLimit;
    float x;
    float y;
//    float oppx;
//    float oppy;
    int val;
    int r;
    int g;
    int b;
    float col;
    bool flag;
    int a;
    int waiting;
    
    pen();
    void setup();
    void update();
    void draw();
    void setR(int red);
    void setG(int green);
    void setB(int blue);
    void setID(int ID);

//    int maxcon;
//    int numcon;
//    int connections[100];
//    void connectTo(int f);
//    bool friendOf(int x);

    sandPainter sands[numsands];
    
};

#endif
