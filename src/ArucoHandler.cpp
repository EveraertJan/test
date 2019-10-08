//
//  ArucoHandler.cpp
//  TeamScheireV2
//
//  Created by Jan Everaert on 07/10/2019.
//

#include "ArucoHandler.hpp"

#include <stdio.h>
#include "ofMain.h"



void drawMarker(float size, const ofColor & color, int id){
    ofDrawAxis(size);
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(0,size*0.5,0);
    ofFill();
    ofSetColor(color,50);
    ofDrawBox(size);
    ofNoFill();
    ofSetColor(color);
    ofDrawBox(size);
    ofDrawBitmapString(id, 0, 0);
    ofPopStyle();
    ofPopMatrix();
    
}

void ArucoHandler::setup(){
    
    
//     setting aruco track
//    grabber.setDeviceID(1);
//    grabber.initGrabber(640, 480);
//    trackVideo = &grabber;
//
//    aruco.setup("intrinsics.int", trackVideo->getWidth(), trackVideo->getHeight());
    
    surfaceGenerator.setup();
    

}

void ArucoHandler::update() {
//    if(TRACK) {
//        video.update();
//        trackVideo->update();
//
//        if(trackVideo->isFrameNew()){
//            aruco.detectBoards(trackVideo->getPixels());
//
//        }
//    }
    surfaceGenerator.update();
}

void ArucoHandler::draw() {
//    trackVideo->draw(0, 0, ofGetWidth(), ofGetHeight());
//
//
//    vector<aruco::Marker> markers = aruco.getMarkers();
//    for(int i = 0; i < markers.size(); i++) {
//        aruco.begin(i);
//        drawMarker(0.15, ofColor::white, markers.at(i).id);
        surfaceGenerator.draw();
//        aruco.end();
//    }
}


