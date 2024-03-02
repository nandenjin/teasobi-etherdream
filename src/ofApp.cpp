#include "ofApp.h"

#define ILDA_XY_MIN -32768
#define ILDA_XY_MAX 32768
#define ILDA_RGBA_MIN 0
#define ILDA_RGBA_MAX 65535

//--------------------------------------------------------------
void ofApp::setup()
{
  ofSetFrameRate(30);
  etherdream.setup();
  while (!etherdream.stateIsFound())
  {
    ofLogNotice() << "Waiting for etherdream...";
    ofSleepMillis(1000);
    etherdream.setup(false);
  }
  etherdream.setPPS(30000);
  ofLogNotice() << "etherdream.stateIsFound() " << etherdream.stateIsFound();
}

//--------------------------------------------------------------
void ofApp::update()
{
  // For when unexpectedly shutted down
  etherdream.checkConnection(true);

  float r = ofGetElapsedTimeMillis() % 1000 / 1000.0;
  vector<ofxIlda::Point> points;
  // Draw circle
  for (int i = 0; i < 900; i++)
  {
    float x = cos(ofDegToRad(i)) * r;
    float y = sin(ofDegToRad(i)) * r;
    ofxIlda::Point p;
    p.x = ofMap(x, -1, 1, ILDA_XY_MIN, ILDA_XY_MAX);
    p.y = ofMap(y, -1, 1, ILDA_XY_MIN, ILDA_XY_MAX);
    p.r = ofMap(1, 0, 1, ILDA_RGBA_MIN, ILDA_RGBA_MAX);
    p.g = ofMap(1, 0, 1, ILDA_RGBA_MIN, ILDA_RGBA_MAX);
    p.b = ofMap(1, 0, 1, ILDA_RGBA_MIN, ILDA_RGBA_MAX);
    p.a = ofMap(1, 0, 1, ILDA_RGBA_MIN, ILDA_RGBA_MAX);
    points.push_back(p);
  }
  points.push_back(ofxIlda::Point(0, 0, 0, 0, 0, 0));
  etherdream.setPoints(points);
}

//--------------------------------------------------------------
void ofApp::draw()
{
}

//--------------------------------------------------------------
void ofApp::exit()
{
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
