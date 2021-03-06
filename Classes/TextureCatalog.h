/*
 *  TextureCatalog.h
 *  hex-game
 *
 *  Created by Johan Ekholm on 2011-04-10.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <map>
#include <string>
#include "toolkit.h"

class TextureMap;

class TextureCatalog {
	static TextureCatalog* _instance;
	std::map<std::string, TextureMap*> _textureMaps;
	
	TextureCatalog() { }

	
public:
	static TextureCatalog* instance() {
		if (_instance == 0) {
			_instance = new TextureCatalog();
		}
		
		return _instance;
	}
	
	static void destroy();
	
	void add(TextureMap* texMap, const std::string& name);
	void addAndLoad(const std::string& name, GLuint texture, int numDivs);
	TextureMap* get(const std::string& name);
	
};

