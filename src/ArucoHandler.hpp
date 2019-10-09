//
//  ArucoHandler.cpp
//  TeamScheireV2
//
//  Created by Jan Everaert on 07/10/2019.
//


#ifndef ArucoHandler_hpp
#define ArucoHandler_hpp

#include "ArucoHandler.hpp"

#include <stdio.h>
#include "ofMain.h"

#include "ofxAruco.h"
#include "SurfaceGenerator.hpp"

class ArucoHandler {
public:
    
    void setup();
    void update();
    void draw(SurfaceGenerator surfaces);
    
    vector<int> returnMarkerIds();
    
    ofVideoPlayer video;
    ofxAruco aruco;
    ofVideoGrabber grabber;
    ofBaseVideoDraws * trackVideo;
    
    
    bool TRACK = false;
};



#endif /* MarkerClass_hpp */
