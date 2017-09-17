#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofSetLineWidth(1.5);

	this->size = 18;
	bool flg = true;
	for (float y = -ofGetHeight() / 2 - size; y < ofGetHeight() / 2 + size; y += this->size + this->size / 2) {
		for (float x = -ofGetWidth() / 2 - size; x < ofGetWidth() / 2 + size; x += this->size * sqrt(3)) {
			ofVec3f location;
			if (flg) {
				location = ofVec3f(x, y, 0);
			} else {
				location = ofVec3f(ofVec3f(x + (this->size * sqrt(3) / 2), y, 0));
			}

			this->particles.push_back(new Particle(location, this->size, ofColor(255)));
		}
		flg = !flg;
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	float distance;
	ofColor change_color;
	for (Particle* p : this->particles) {
		p->update();	

		change_color.setHsb(ofMap(ofNoise(p->getLocation().x * 0.005, p->getLocation().y * 0.005, ofGetFrameNum() * 0.015), 0, 1, 0, 255), 255, 255);
		p->changeColor(change_color);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();

	for (Particle* p : this->particles) {
		p->draw();
	}
	
	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::drawHand(Leap::Hand hand) {

}

//--------------------------------------------------------------
void ofApp::drawFinger(Leap::Finger finger) {

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
