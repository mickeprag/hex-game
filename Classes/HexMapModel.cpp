//
//  HexMap.m
//  igame
//
//  Created by Johan Ekholm on 2010-08-15.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#include "HexMapModel.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>


HexMapModel::~HexMapModel() {
    _hexes.clear();

}

HexMapModel::HexMapModel(int width, int height) {
    using namespace std;
    HexState state;
	_width = width;
	_height = height;
    string data = "0 0 0 3 3 3 0 0\n1 1 1 1 3 1 1 1\n2 2 1 1 2 2 0 2\n1 2 1 1 1 2 1 2\n0 1 0 2 0 1 0 2\n1 2 1 2 1 0 1 2\n0 1 0 2 0 1 0 2\n1 2 1 2 1 2 1 2\n";
    istringstream dataStream(data);
    vector<string> tokens;
    vector<string>::const_iterator it;
    int number = 0;
    
    copy(istream_iterator<string>(dataStream), istream_iterator<string>(), back_inserter<vector<string> >(tokens));
    
    it = tokens.begin();
    
    for (int i = 0; i < _height; i++) {
		for (int j = 0; j < _width; j++) {
            state.pos = MPointMake(j, i);

            if (it != tokens.end()) {
                (stringstream(*it) >> number) ? state.value = number : state.value = 0;
            } else {
                state.value = 0;
            }
            _hexes[i * _width + j] = state;
            ++it;
        }
    }
}

HexMapModel::HexMapModel(int width, int height, const std::string& data) {
    using namespace std;
    HexState state;
	_width = width;
	_height = height;
    istringstream dataStream(data);
    vector<string> tokens;
    vector<string>::const_iterator it;
    int number = 0;
    
    copy(istream_iterator<string>(dataStream), istream_iterator<string>(), back_inserter<vector<string> >(tokens));
    
    it = tokens.begin();
    
    for (int i = 0; i < _height; i++) {
		for (int j = 0; j < _width; j++) {
            state.pos = MPointMake(j, i);
            
            if (it != tokens.end()) {
                (stringstream(*it) >> number) ? state.value = number : state.value = 0;
            } else {
                state.value = 0;
            }
            _hexes[i * _width + j] = state;
            ++it;
        }
    }
}

std::map<int, HexState> HexMapModel::getAllHexes() {
    return _hexes;
}

int HexMapModel::getHeight() {
    return _height;
}

int HexMapModel::getHexValue(const MPoint& hex) {
    return _hexes[hex.y * _width + hex.x].value;
}

int HexMapModel::getHexValue(int x, int y) {
    return _hexes[y * _width + x].value;
}

int HexMapModel::getWidth() {
    return _width;
}
