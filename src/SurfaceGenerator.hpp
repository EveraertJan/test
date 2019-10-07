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

class SurfaceGenerator {
    
public:
    void setup();
    void update();
    void draw();
    
    ofVideoPlayer background;
    ofVideoPlayer foreground;
    ofVideoPlayer foregroundMask;
    ofVideoPlayer interaction;
    ofFbo videoFBO;

    
};

#endif /* SurfaceClass_hpp */
