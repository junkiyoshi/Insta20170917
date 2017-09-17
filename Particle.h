#pragma once

#include "ofMain.h"

class Particle {
public:
	Particle();
	Particle(ofVec3f location, float radius, ofColor c);
	~Particle();

	void update();
	void draw();

	void changeColor(ofColor body_color);

	ofVec3f getLocation();

private:
	float radius;
	ofVec3f location;
	ofColor body_color;
	ofColor change_color;
};