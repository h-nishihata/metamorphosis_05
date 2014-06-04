#include "TestLayer3.h"

//--------------------------------------------------------------------------------------------------------------
void TestLayer3::setup(){
    
    x = -50;
    y = -10;
    speedX = 0.05;
    speedY = 0.05;
    img.loadImage("ohkoku.jpg");
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer3::update(){
    
    x += speedX;
    y += speedY;
    
    if (x >= 0 || x <= -844) {
        speedX = speedX*-1;
    }
    if (y >= 0 || y <= -208) {
        speedY = speedY*-1;
    }
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer3::draw(){
    
    ofEnableAlphaBlending();
    ofBackground(255,255,255,0);
    
    ofSetColor(0);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
//    img.draw(x, y, img.width, img.height);
    
}
