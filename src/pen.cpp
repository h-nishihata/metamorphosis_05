#include "pen.h"

pen::pen(){
    
    pal = (identify+(int)ofRandom(100/5))%100;
    //    cout << pal << endl;
    float vt = 2;
    float vvt = 0.1;
    float ot = ofRandom(TWO_PI);
    
    for (identify=0; identify<100; identify++) {
        
        tinc = ot + (1.1-identify/100) * 2 * identify * TWO_PI/100;
        vx = vt*sin(tinc);
        vy = vt*cos(tinc);
        vvt -= 0.00033;
        vt += vvt;
        
    }
    /*
     t = (int)ofRandom(0,360)*PI/180;
     tv = ofRandom(0.1, 0.2);
     if(ofRandom(100)<50){tv*=-1;}
     rad = ofRandom(1, 100);
     */
    centx = ofGetWidth()/2 + vx*2;
    centy = ofGetHeight()/2 + vy*2;
    
    waitCnt = ofRandom(0, 300);
    step = 0;
    
    col = 0;
    flag = false;
    a = ofRandom(0, 255);
    waiting = ofRandom(0,80);
    
    //    radius = ofRandom(20);
    //    radiusNoise = ofRandom(10);
    //    radLimit = ofRandom(10) + 40;
    //    val = ofRandom(100);
    
}
//--------------------------------------------------------------
void pen::setup(){
    
}
//--------------------------------------------------------------
void pen::setR(int red){
    r = red;
}

//--------------------------------------------------------------
void pen::setG(int green){
    g = green;
}

//--------------------------------------------------------------
void pen::setB(int blue){
    b = blue;
}

//--------------------------------------------------------------
void pen::setID(int ID){
    identify = ID;
}

//--------------------------------------------------------------
void pen::update(){
    //    t+=tv;
    //    if (flag_r == false) {
    //
    //        radius+=0.1;
    //        if(radius > radLimit) {
    //            flag_r = true;
    //        }
    //
    //    }else if (flag_r == true){
    //
    //        radius-=0.1;
    //        if(radius < 0) {
    //            flag_r = false;
    //        }
    //
    //    }
    
    
    
    //    if (flag == false) {
    //        r+=0.1;
    //        g+=0.1;
    //        b+=0.1;
    //        if(r>=255 || g>=255 || b>=25){
    //            flag = true;
    //        }
    //    }else if (flag == true){
    //        r-=0.1;
    //        g-=0.1;
    //        b-=0.1;
    //        if(r<=0 || g<=0 || b<=0){
    //            flag = false;
    //        }
    //    }
    //
    //    if(waiting < 80){
    //        waiting++;
    //    }else{
    //        if(a > 0){ a -=3; }else{ a = 255;}
    //    }
    
    //  **********
    
    centx += vx;
    centy += vy;
    
    float ax = 0.0;
    float ay = 0.0;
    int lencon = ofRandom(50)+10;
    vx += (this[pal].centx - centx)/1000;
    vy += (this[pal].centy - centy)/1000;
/*
    for (int n=0; n<10; n++) {
        float ddx = this[n].centx-centx;
        float ddy = this[n].centy-centy;
        float d = sqrt(ddx*ddx + ddy*ddy);
        float t = atan2(ddy,ddx);
        if (d>lencon) {
            ax += 10.0 * cos(t);
            ay += 10.0 * sin(t); // 10.0
        }else if (d<lencon) {
            ax += (lencon-d)/10 * cos(t+PI); //(lencon-d)/10 *
            ay += (lencon-d)/10 * sin(t+PI);
        }
    }
 */


    if (flag_f == false) {
        vx *= .99;
        vy *= .99;
        if(vx < 1 || vy < 1){
//            flag_f = true;
        }

    }else if (flag_f == true){
        vx *= 1.01;
        vy *= 1.01;
        if(vx > 5 || vy > 5){
            flag_f = false;
        }
        
    }
    
    //    if (centx >= 1440 || centx <= 0) {
    //        vx = vx * -1;
    //    }
    //    if (centy >= 900 || centy <= 0) {
    //        centy = ofRandom(900);
    //    }
    
    
    time++;
    
    
    
//    if (flag_t == false) {
//        vx += ax/100;
//        vy += ay/100;
//        if(time > 50){
//            flag_t = true;
//        }
//        
//    }else if (flag_t == true){
//        vx -= ax/100;
//        vy -= ay/100;
//        if(time > 100){
//            flag_t = false;
//            time = 0;
//        }
//        
//    }
    
    
    
    if (vx == vy) {
        vx += ofRandom(-0.1, 0.1);
        vy += ofRandom(-0.1, 0.1);
    }
    
}

//--------------------------------------------------------------
void pen::draw(){
    
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
    //    if (step < waitCnt) {
    //        step++;
    //    }
    //    else {
    
    //    x = centx + rad*cos(t);
    //    y = centy + rad*sin(t);
    
    ofCircle(centx, centy, 1);
    for (int n=0; n<=1; n++) {
    for (int i=0; i < numsands; i++) {
        sands[i].render(centx, centy, this[n].centx, this[n].centy);
    }
    }
    //    }
    
}

/*
 //--------------------------------------------------------------
 void pen::connectTo(int f){
 
 if (numcon < maxcon) {
 if (! friendOf(f)) {
 connections[numcon] = f;
 numcon++;
 }
 }
 
 }
 
 //--------------------------------------------------------------
 bool pen::friendOf(int x){
 
 bool isFriend = false;
 for (int n=0; n<numcon; n++) {
 if (connections[n] == x) {
 isFriend = true;
 }
 }
 return isFriend;
 
 }
 */

