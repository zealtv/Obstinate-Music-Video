#pragma once

#include "ofMain.h"
#include "ofxSyphon.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
  
    ofTexture videoTexture;
    ofVideoGrabber videoGrabber;
  
    int xStep;
    int yStep;
   
    float amp;
    bool color;
  
    int threshold;
  
    ofPixels pixels;
    ofColor lineColor;
    ofColor fillColor;
  
    ofVideoPlayer videoPlayer;
  
      ofFbo syphonClientFbo;
      ofFbo fbo;
  
    ofxSyphonServer mainOutputSyphonServer;
    ofxSyphonClient syphonClient;
  
    ofShader shader;

		
};
