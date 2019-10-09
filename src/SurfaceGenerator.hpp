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
    void draw(int drawX, int drawY, int drawWidth, int drawHeight, int SOURCE, float scale, int subX, int subY, int subWidth, int subHeight);
    void loadNewSource(string source);
    
    ofVideoPlayer background;
    ofVideoPlayer foreground;
    ofVideoPlayer foregroundMask;
    ofVideoPlayer interaction;
    ofVideoPlayer interactionMask;
    
    ofFbo videoFBO;

    
};

#endif /* SurfaceClass_hpp */
