/*
 *  CentralControl.h
 *  hex-game
 *
 *  Created by Johan Ekholm on 2011-04-16.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

class InputManager;
class HexMap;
class ViewController;
class ViewControllerManager;
class ModelManager;
class StringImage;
class UnitFactory;

struct TouchEvent;
struct GPoint;

namespace ControlMode {
    const int BATTLE = 1;
    const int BATTLE_FOCUS = 2;
    const int ADVENTURE = 3;
    const int MENU = 4;
};

class CentralControl {
	static CentralControl* _instance;
	int _mode;
    int _timer;
	InputManager* _input; 
    ModelManager* _modelManager;
    ViewControllerManager* _viewControllerManager;
    UnitFactory* _unitFactory;
    StringImage* _stringImage;

    CentralControl();

public:
	static CentralControl* instance() {
		if (_instance == 0) {
			_instance = new CentralControl();
		} 
		return _instance;
	}
    
    static void destroy();
    
	void update();
	void draw();
    void handleEventAdventureNormal(const TouchEvent& event);
    void handleEventMenu(const TouchEvent& event);
	void handleEventNormal(const TouchEvent& event);
	void handleEventFocus(const TouchEvent& event);

	void touchesBegan(const GPoint& touchPoint);
	void touchesMoved(const GPoint& touchPoint);
	void touchesEnded(const GPoint& touchPoint);
	void touchesCancelled(const GPoint& touchPoint);
		
public:
	void switchMode(int mode);
    
};

