#include "TestLayer2.h"

//--------------------------------------------------------------------------------------------------------------
void TestLayer2::setup(){
    
    fbo.allocate(1440, 900);
    processFbo.allocate(1440, 900);
    
    image.loadImage("tohaku.jpg");
    pixels = image.getPixels();
    
    for (int i=0; i<NUM; i++) {
        
        pos = pens[i].centy * 2239 + pens[i].centx;
        red = pixels[pos *3];
        green = pixels[pos *3 +1];
        blue =  pixels[pos *3 +2];
        pens[i].setR(red);
        pens[i].setG(green);
        pens[i].setB(blue);
        pens[i].setID(i);
        
    }
    
    alpha = 60;
    end_0 = true;
    end_1 = true;
    
    /*
     for (int k=0; k<NUM*2.2; k++) {
     int a = ofRandom(NUM);
     int b = (a + ofRandom(22));
     
     if (b > NUM) {
     b = 0;
     }else if (b < 0){
     b = 0;
     }
     if (a != b) {
     pens[a].connectTo(b);
     pens[b].connectTo(a);
     }
     
     //     cout << b << endl;
     //     cout << a << " made friends with " << b <<endl;
     }
     
     //     for (int j=0; j<NUM; j++) {
     //     cout << pens[j].centx << endl;
     //     }
     */
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer2::update(){
    
    for (int i=0; i<NUM; i++) {
        pens[i].update();
    }
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer2::draw(){
    
    ofTranslate(0, 900);
    ofRotateX(180);
    
    
    
    fbo.begin();
    ofEnableAlphaBlending();
    ofBackground(0,0,0,0);
    processFbo.draw(0, 0);
    fbo.end();
    
    
    
    processFbo.begin();
    ofSetColor(255,255,255,255);
    for (int i=0; i<NUM; i++) {
        pens[i].draw();
    }
    
    // setting
    if (end_0 == true) {
        waiting_1++;
        //        fading(40,0,40,200);
        if (alpha < 60) {
            alpha+=0.1;
        }
    }
    
    // phase 1
    if (end_1 == true) {
        if (waiting_2 < 100) {
            waiting_2++;
        }else{
            end_0 = false;
            end_2 = true;
            //            fading(0,0,0,0);
            if (alpha > 0) {
                alpha-=5;
            }
        }
    }
    
    // elase all
    if (end_2 == true) {
        if (waiting_3 < 100) {
            waiting_3++;
        }else{
            end_1 = false;
            end_3 = true;
            //            fading(0,0,0,255);
            if (alpha < 60) {
                alpha+=0.1;
            }
        }
    }
    
    // phase 2
    if (end_3 == true) {
        if (waiting_4 < 100) {
            waiting_4++;
        }else{
            end_2 = false;
            end_4 = true;
            //            fading(0,0,0,0);
            if (alpha > 0) {
                alpha-=5;
            }
        }
    }
    
    // reset
    if (end_4 == true) {
        if (waiting_5 < 100) {
            waiting_5++;
        }else{
            waiting_1 = waiting_2 = waiting_3 = waiting_4 = waiting_5 = 0;
            end_2 = end_3 = end_4 = false;
            end_0 = end_1 = true;
        }
    }
    
//    ofSetColor(0,0,0,alpha);
//    ofRect(0,0,ofGetWidth(),ofGetHeight());
    processFbo.end();
    
    
    ofSetHexColor(0xffffff);
    fbo.draw(0,0);

}

/*
 //--------------------------------------------------------------------------------------------------------------
 void TestLayer2::fading(int r, int g, int b, int a){
 
 ofSetColor(r, g, b, a);
 ofRect(0,0,ofGetWidth(),ofGetHeight());
 
 }
 */