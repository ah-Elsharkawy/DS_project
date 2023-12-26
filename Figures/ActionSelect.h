#pragma once

#include"..\ApplicationManager.h"
#include "Action.h"
#include <vector>

using namespace std;

class ActionSelect : public Action
{
	Point P;
	//bool multiSelect;
	//vector <CFigure*> selectedFigures;
public:
	// make that constructor take x & y when creation
	//ActionSelect(ApplicationManager* pApp, Point _P, bool _multiSelect);
	ActionSelect(ApplicationManager* pApp, Point _P);
	//  Select Fugure 
	virtual void Execute();
};

