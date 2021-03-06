/*
 *  ViewController.mm
 *  hex-game
 *
 *  Created by Johan Ekholm on 2011-04-17.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ViewController.h"
#include "toolkit.h"
#include "InputManager.h"

ViewController::ViewController() {
    _hasFocus = false;
}

ViewController::ViewController(const GPoint& pos, GLfloat width, GLfloat height, int layer) {
    _hasFocus = false;
    _pos = pos;
    _width = width;
    _height = height;
    _layer = layer;
}

int ViewController::getLayer() {
    return _layer;
}

GPoint ViewController::getPosition() {
    return _pos;
}

bool ViewController::isWithin(const GPoint& point) {
	if (point.x >= _pos.x - _width/2 && point.x <= _pos.x + _width/2 && point.y >= _pos.y - _height/2 && point.y <= _pos.y + _height/2) {
		return true;
	} else {
		return false;
	}
}

void ViewController::setFocus(bool hasFocus) {
    _hasFocus = hasFocus;
}

void ViewController::update() {
    return;
}

/*bool ViewController::handleEvent(const TouchEvent& event) {
	if (this->isWithin(event.point)) {
		this->reactToEvent(event.type);
		return true;
	}
	return false;
}*/
