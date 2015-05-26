#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

  ofSetFrameRate( 60 );
  ofEnableAlphaBlending();
  
  
  mainOutputSyphonServer.setName("Screen Output");
  syphonClient.setup();
  syphonClient.set( "Main Output", "VDMX5" );
  
  syphonClientFbo.allocate( ofGetWidth(), ofGetHeight(), GL_RGBA );
  syphonClientFbo.begin();
  ofClear( 0 );
  syphonClientFbo.end();

  fbo.allocate( ofGetWidth(), ofGetHeight(), GL_RGBA );
  fbo.begin();
  ofClear( 0 );
  fbo.end();
  
  //load shader if needed
  //shader.load( "shader" );
  
  
  //tweakable shizz
  xStep = 204;
  yStep = 153;
  
  amp = 0.4;
  threshold = 50;
  
  
  //white on black
  //lineColor = ofColor( 255, 255, 255, 150 );
  //fillColor = ofColor( 0, 0, 0, 255 );
  
  //black on white
  lineColor = ofColor( 0, 0, 0, 255 );
  fillColor = ofColor( 255, 255, 255, 255 );
  
  //assign pixel colour to line segements
  color = false;

}

//--------------------------------------------------------------
void ofApp::update(){
  
  syphonClientFbo.begin();
  syphonClient.draw(0, 0, ofGetWidth(), ofGetHeight() );
  syphonClientFbo.end();
  
  videoTexture = syphonClientFbo.getTextureReference();
  
  videoTexture.readToPixels( pixels );
}

//--------------------------------------------------------------
void ofApp::draw(){

  
  fbo.begin();
  ofClear( fillColor );
  
  
  ofSetColor( lineColor);
  
  int stepWidth = ofGetWidth() / xStep;
  int stepWidthCam = videoTexture.getWidth() / xStep;

  int stepHeight = ofGetHeight() / yStep;
  int stepHeightCam = videoTexture.getHeight() / yStep;
  
  
  ofSetColor( lineColor );
  ofSetLineWidth( 3 );
  
  int cY = 0;

  for( cY = 0; cY < yStep; cY++ )
  {
  
    ofPoint lastpoint;;
    ofColor currentColor;

    for( int i = 1; i < xStep; i++ )
    {
      
      currentColor = pixels.getColor( i * stepWidthCam , cY * stepHeightCam );
      
      ofPoint thisPoint(  i * stepWidth,  cY * stepHeight - currentColor.getBrightness() * amp + stepHeight );
      
      if ( currentColor.getBrightness() >= threshold )
      {
        //apply pixel colour to line segement.
        if(color)
        {
          currentColor = ofColor( currentColor[0], currentColor[1], currentColor[2], 200 );
          ofSetColor( currentColor );
        }
        else
        {
          //adjust alpha of line segement according to brightness of pixel
          ofSetColor( lineColor.r, lineColor.g, lineColor.b, ofMap( currentColor.getBrightness(), threshold, 255, 0, 255)  );
        }

        if( i == 1 )
        {
          lastpoint = thisPoint;
        }
        
        ofLine( lastpoint[0], lastpoint[1], thisPoint[0], thisPoint[1] );
      
      }
      lastpoint = thisPoint;
    }
    
  }
  
  fbo.end();
  
  //Shader ready to do any post required.
  
  //shader.begin();
  //shader.setUniformTexture( "tex0", fbo.getTextureReference(), 0 );
  ofSetColor( 255 );
  fbo.draw( 0, 0, ofGetWidth(), ofGetHeight() );
  //shader.end();
  
  mainOutputSyphonServer.publishScreen();
  
  
  
}
































//--------------------------------------------------------------
void ofApp::keyPressed(int key){

  if( key == '.' )
  {
    xStep++;
    cout << xStep << endl;
  }
  if( key == ',' )
  {
    xStep--;
  }
  if( key == 'c' )
  {
    color = !color;
  }
  if(key == 'r') shader.load("shader");
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
