#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    aruco.setup();
    
    
    sound.load("space.wav");
    sound.setVolume(10);
//    sound.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    aruco.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    aruco.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 't') {
        aruco.TRACK = true;
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
