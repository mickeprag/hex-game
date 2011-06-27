/*
 *  ModelManager.h
 *  hex-game
 *
 *  Created by Johan Ekholm on 2011-05-02.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <vector>
#include <map>
#include "toolkit.h"

class UnitModel;
class HexMapModel;

class ModelManager {
    static ModelManager* _instance;
	std::map<int, UnitModel*> _units;
    HexMapModel* _map;
    int _unitIdCounter;
    
    ModelManager();

public:
    static ModelManager* instance() {
		if (_instance == 0) {
			_instance = new ModelManager();
		}		
		return _instance;
	}
    
    static void destroy();

	void add(UnitModel*);
    void remove(int unitId);
    void setMap(HexMapModel* map);
    HexMapModel* getMap();
    void tick();
    UnitModel* getUnitAtPos(const MPoint& pos);
    UnitModel* getUnitById(int unitId);
    UnitModel* getClosestTo(const MPoint& pos);
    std::vector<UnitModel*> getAllUnits();
};

