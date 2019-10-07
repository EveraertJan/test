//
//  SurfaceGenerator.cpp
//  TeamScheireV2
//
//  Created by Jan Everaert on 07/10/2019.
//

#include "SurfaceGenerator.hpp"

void SurfaceGenerator::setup() {
    ofEnableAlphaBlending();

    
    background.load("water/background.mp4");
    background.play();
    foreground.load("water/foreground.mov");
    foreground.play();
    foregroundMask.load("water/foregroundMask.mov");
    foregroundMask.play();
    
    
    
    videoFBO.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    
    videoFBO.begin();
    ofClear(0, 0, 0, 0);
    videoFBO.end();

}

void SurfaceGenerator::update() {
    
    background.update();
    foreground.update();
    foregroundMask.update();
    
    
    videoFBO.begin();
    ofEnableAlphaBlending();
    ofClear(0, 0, 0, 0);
    
    background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    
    
    ofTexture mask;
    mask.allocate(foreground.getWidth(), foreground.getHeight(), GL_RGBA);
    ofPixels fgmask = foregroundMask.getPixels();
    fgmask.setImageType(OF_IMAGE_COLOR_ALPHA);
    fgmask.setChannel(3, fgmask.getChannel(0));
    mask.loadData(fgmask);

    ofFbo result;
    result.allocate(foreground.getWidth(), foreground.getHeight(), GL_RGBA);
    
    result.getTexture().setAlphaMask(mask);
    
    result.begin();
    ofClear(0, 0, 0, 0);
    ofPushMatrix();
    foreground.draw(0, 0, foreground.getWidth(), foreground.getHeight());
    ofPopMatrix();
    result.end();
    
    result.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    ofDisableAlphaBlending();
    videoFBO.end();
    ofTexture tex = videoFBO.getTexture();
    
    
}

void SurfaceGenerator::draw() {
    
    ofPushMatrix();
    
    ofScale(0.0005);
    ofEnableAlphaBlending();
    videoFBO.draw(0, 0);
    ofDisableAlphaBlending();
    
    ofPopMatrix();
    
}



