#ifndef ACTION_ADD_SQUARE_H
#define ACTION_ADD_SQUARE_H

#include "Action.h"

//Add Square Action class
class ActionAddSquare: public Action
{
	Point p;
public:
	ActionAddSquare(ApplicationManager *pApp);
	
	//Add Square to the ApplicationManager
	virtual void Execute() ;
	
};

#endif