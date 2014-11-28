#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0,0,0);
    ofSetFrameRate(12);
    
    img.loadImage("genpei_.TIF");
    
    rgbaFbo.allocate(1920, 1200, GL_RGBA);
    
    rgbaFbo.begin();
    ofClear(255,255,255, 0);
    rgbaFbo.end();
    
    pixels = img.getPixels();
    
    for (int i=0; i<NUM; i++) {
        
        pos = pens[i].centy * 4180 + pens[i].centx;
        red = pixels[pos *3];
        green = pixels[pos *3 +1];
        blue =  pixels[pos *3 +2];
        pens[i].setR(red);
        pens[i].setG(green);
        pens[i].setB(blue);
        pens[i].setID(i);
        
    }
    
    fadeAmnt = 255;
    
    x = -500;
    y = -500;
    speedX = 0.1;
    speedY = 0.1;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (startDraw<20) {
        startDraw ++ ;
    }
    
    ofEnableAlphaBlending();
    
    rgbaFbo.begin();
    drawFboTest();
    for (int i=0; i<NUM; i++) {
        pens[i].update();
    }
    rgbaFbo.end();
    
    x += speedX;
    y += speedY;
    
    if (x >= 0 || x <= -2260) {
        speedX = speedX*-1;
    }
    if (y >= 0 || y <= -2025) {
        speedY = speedY*-1;
    }
    
}

//--------------------------------------------------------------
void ofApp::drawFboTest(){
    
    for (int i=0; i<NUM; i++) {
        pens[i].draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofHideCursor();
    
    ofSetColor(255,255,255);
    img.draw(x, y, img.width, img.height);
    rgbaFbo.draw(0,0);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
