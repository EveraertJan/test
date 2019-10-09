#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    aruco.setup();
    
    
    sound.load("space.wav");
    sound.setVolume(10);
//    sound.play();
    
    surfaceGenerator.setup();
    
    presets.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    aruco.update();
    surfaceGenerator.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(DISPLAY_MODE == 0) {
        aruco.draw(surfaceGenerator);
    }
    else {
        presets.draw(surfaceGenerator, DISPLAY_MODE);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 't') {
        aruco.TRACK = true;
    }
    if(key == '0') {
        DISPLAY_MODE = 0;
    }
    if(key == '1') {
        DISPLAY_MODE = 1;
    }
    if(key == '2') {
        DISPLAY_MODE = 2;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == 't') {
        aruco.TRACK = false;
    }
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
