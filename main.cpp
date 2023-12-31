#include "ApplicationManager.h"
#include "GUI\GUI.h"
#include "ِActionPlayBy.h"


int ActionPlayBy::correct = 0;
int ActionPlayBy::wrong = 0;
string ActionPlayBy::inGameType = "";
ActionType ActionPlayBy::type = EMPTY;

int main()
{
	/*
	GUI* g=new GUI();
	
	
	window* w=g->CreateWind(200, 300, 10, 10);
	int x, y;
	w->WaitMouseClick(x, y);
	*/
	
	ApplicationManager AppManager;
	AppManager.Run();		
	return 0;
}

