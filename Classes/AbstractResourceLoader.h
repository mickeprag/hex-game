/*
 *  AbstractResourceLoader.h
 *  hex-game
 *
 *  Created by Micke Prag on 2011-08-15.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "toolkit.h"
#include <string>

class AbstractResourceLoader {
public:
    AbstractResourceLoader();
    virtual ~AbstractResourceLoader();
    
    void load();
    static std::string loadLuaScript(const std::string &scriptName);
protected:
    virtual GLuint loadTexture(const std::string &filename) = 0;
};
