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
    foreground.load("water/foreground.mp4");
    foreground.play();
    foregroundMask.load("water/foregroundMask.mp4");
    foregroundMask.play();
    interaction.load("water/interaction.mp4");
    interaction.play();
    interactionMask.load("water/interactionMask.mp4");
    interactionMask.play();
    
    
    
    videoFBO.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    
    videoFBO.begin();
    ofClear(0, 0, 0, 0);
    videoFBO.end();

}

void SurfaceGenerator::update() {
    
    background.update();
    foreground.update();
    foregroundMask.update();


    interaction.update();
    interactionMask.update();
    
    
    videoFBO.begin();
    ofEnableAlphaBlending();
    ofClear(0, 0, 0, 0);
    
    background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    
    ofTexture fgtmask;
    fgtmask.allocate(1024, 512, GL_RGBA);
    ofPixels fgmask = foregroundMask.getPixels();
    fgmask.resize(1024, 512);
    fgmask.setImageType(OF_IMAGE_COLOR_ALPHA);
    fgmask.setChannel(3, fgmask.getChannel(0));
    fgtmask.loadData(fgmask);
    ofFbo fgresult;
    fgresult.allocate(1024, 512, GL_RGBA);
    fgresult.getTexture().setAlphaMask(fgtmask);
    fgresult.begin();
    ofClear(0, 0, 0, 0);
    foreground.draw(0, 0,1024, 512);
    fgresult.end();
    fgresult.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

    
    
    ofTexture intMask;
    intMask.allocate(1024, 512, GL_RGBA);
    ofPixels inMask = interactionMask.getPixels();
    inMask.resize(1024, 512);
    inMask.setImageType(OF_IMAGE_COLOR_ALPHA);
    inMask.setChannel(3, inMask.getChannel(0));
    intMask.loadData(inMask);
    ofFbo intResult;
    intResult.allocate(1024, 512, GL_RGBA);
    intResult.getTexture().setAlphaMask(intMask);
    intResult.begin();
    ofClear(0, 0, 0, 0);
    interaction.draw(0, 0,1024, 512);
    intResult.end();
    intResult.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    
    
    ofDisableAlphaBlending();
    videoFBO.end();
    
    
}

void SurfaceGenerator::draw(int drawX, int drawY, int drawWidth, int drawHeight, int SOURCE, float scale, int subX, int subY, int subWidth, int subHeight) {
    
    
    ofPushMatrix();
    ofScale(scale);
    videoFBO.getTexture().drawSubsection(drawX, drawY, drawWidth, drawHeight, subX, subY, subWidth, subHeight);
    ofPopMatrix();
    
}

void SurfaceGenerator::loadNewSource(string source) {
    
    background.load(source + "/background.mp4");
    background.play();
    foreground.load(source + "/foreground.mp4");
    foreground.play();
    foregroundMask.load(source + "/foregroundMask.mp4");
    foregroundMask.play();
    interaction.load(source + "/interaction.mp4");
    interaction.play();
    interactionMask.load(source + "/interactionMask.mp4");
    interactionMask.play();
    
}



