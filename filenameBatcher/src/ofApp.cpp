#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

  font.loadFont( "Courier New Bold.ttf", 12 );
  
  movie.loadMovie("movie.mov");
  currentFrame = 0;


}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){

  
  movie.setFrame( currentFrame );
  movie.update();
  
  ofClear( 255, 255, 255, 255 );
  
  ofSetColor( 255, 255, 255 );
  movie.draw( 25, 25, 1024, 768 );
  
  ofSetColor( 0 );
  string watermark = "Packwood - Obstinate :: frame " + ofToString(currentFrame);
  font.drawString( watermark, 75, 720 );
  
  image.grabScreen( 0 , 0, ofGetWidth(), ofGetHeight() );
  image.saveImage( "frames/frame" + ofToString( currentFrame ) + ".png" );
  
  //ofExit();
  currentFrame++;
  
  if( currentFrame > movie.getTotalNumFrames() ) ofExit();
  
  
  
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
