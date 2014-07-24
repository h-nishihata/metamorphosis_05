#include "pen.h"

pen::pen(){
    
    /*
     pal = (identify+(int)ofRandom(100/5))%100;
     
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
     
     
     
     if(ofRandom(100)<50){
     setDirection = true;
     }else{
     setDirection = false;
     }
     */
    
    
    //    centx = ofGetWidth()/2 + vx*2;
    //    centy = ofGetHeight()/2 + vy*2;
    centx = ofRandom(ofGetWidth());
    centy = ofRandom(ofGetHeight());
    
    if(ofRandom(100) > 90){
        setEraser = true;
    }else{
        setEraser = false;
    }
    
    waitCnt = ofRandom(0, 300);
    step = 0;
    
    flag_c = false;
    a = ofRandom(255) + 100;
    waiting = ofRandom(0,80);
    
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
    //    pal = (identify+(int)ofRandom(100/5))%100;
    
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
    
    
    if (flag_c == false) {
        r+=0.1;
        g+=0.1;
        b+=0.1;
        if(r>=255 || g>=255 || b>=255){
            flag_c = true;
        }
    }else if (flag_c == true){
        r-=0.1;
        g-=0.1;
        b-=0.1;
        if(r<=50 || g<=50 || b<=50){
            flag_c = false;
        }
    }
    
    
    if(waiting < 80){
        waiting++;
    }else{
        if(a > 100){ a --; }else{ a = 255;}
    }
    
    
    //  *****   velocity    *****
    
    
    time++;
    
    centx += vx;
    centy += vy;
    
    //    vx += (this[pal].centx - centx);
    //    vy += (this[pal].centy - centy);
    
    float ax = 0.0;
    float ay = 0.0;
    
    int lencon = ofRandom(50)+10;
    for (int n=0; n<10; n++) {
        float ddx = this[n].centx-centx;
        float ddy = this[n].centy-centy;
        float d = sqrt(ddx*ddx + ddy*ddy);
        float t = atan2(ddy,ddx);
        if (d>lencon) {
            ax += 10.0 * cos(t);
            ay += 10.0 * sin(t);
        }else if (d<lencon) {
            ax += (lencon-d)/10 * cos(t+PI);
            ay += (lencon-d)/10 * sin(t+PI);
        }
    }
    
    vx *= 0.98;
    vy *= 0.98;
    
    
    if (flag_d == false) {
        vx += ax/200;
        vy += ay/200;
        if(time > ofRandom(100)){
            flag_d = true;
        }
        
    }else if (flag_d == true){
        vx -= ax/200;
        vy -= ay/200;
        if(time > ofRandom(500)){
            flag_d = false;
            time = 0;
        }
        
    }
    
    
    
    if (centx >= 1920 || centx <= 0) {
        centx = ofRandom(ofGetWidth());
        centy = ofRandom(ofGetHeight());
    }
    if (centy >= 1200 || centy <= 0) {
        centx = ofRandom(ofGetWidth());
        centy = ofRandom(ofGetHeight());
    }
    
    
    
    if (vx == vy) {
        vx += ofRandom(-0.1, 0.1);
        vy += ofRandom(-0.1, 0.1);
    }
    
}

//--------------------------------------------------------------
void pen::draw(){
    
    ofEnableSmoothing();
    ofEnableAlphaBlending();
        
    //    x = centx + rad*cos(t);
    //    y = centy + rad*sin(t);
    
    if (setEraser) {
        ofSetColor(211, 204, 97, 30);
    }else{
        ofSetColor(r,g,b,a);
    }
    
    ofCircle(centx, centy, 1);
    
    for (int n=0; n<=1; n++) {
        //        for (int i=0; i < numsands; i++) {
        sands.render(centx, centy, this[n].centx, this[n].centy);
        //        }
    }
    
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

