//
//  SurfaceClass.hpp
//  testVideoMap
//
//  Created by Jan Everaert on 30/07/2019.
//

#ifndef SurfaceClass_hpp
#define SurfaceClass_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxXmlSettings.h"

#include "ofxOMXPlayer.h"

class SurfaceGenerator {
    
public:
    void setup();
    void update();
    void draw();

    ofxOMXPlayer background;
    ofxOMXPlayer foreground;
    ofxOMXPlayer foregroundMask;
    ofxOMXPlayer interaction;
    ofxOMXPlayer interactionMask;
    ofFbo videoFBO;

    
};

#endif /* SurfaceClass_hpp */
