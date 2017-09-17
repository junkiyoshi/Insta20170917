#include "Particle.h"

Particle::Particle() : Particle(ofVec3f(0, 0, 0), 10, ofColor(255)) {

}

Particle::Particle(ofVec3f location, float radius, ofColor body_color) {
	this->location = location;
	this->radius = radius;
	this->body_color = body_color;
}

Particle::~Particle() {

}

void Particle::update() {

}

void Particle::changeColor(ofColor body_color)
{
	this->body_color = body_color;
}

void Particle::draw() {
	ofPushMatrix();
	ofTranslate(this->location);
	ofNoFill();

	ofSetColor(this->body_color);
	ofBeginShape();
	float x, y;
	for (int i = 0; i < 360; i += 60) {
		x = this->radius * cos(DEG_TO_RAD * (i + 90));
		y = this->radius * sin(DEG_TO_RAD * (i + 90));
		ofVertex(x, y, 0);
	}
	ofEndShape(true);

	ofPopMatrix();
}

ofVec3f Particle::getLocation()
{
	return this->location;
}