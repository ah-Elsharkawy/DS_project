#include "ActionPlayReset.h"
#include "../ApplicationManager.h"
#include "../GUI/GUI.h"
#include "Action.h"
#include "ِActionPlayBy.h"

ActionPlayReset::ActionPlayReset(ApplicationManager* pApp):Action(pApp) {};

void ActionPlayReset::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	ActionPlayBy::type = EMPTY;
	ActionPlayBy::correct = 0;
	ActionPlayBy::wrong = 0;
	ActionPlayBy::inGameType = "";
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("Game reset sucessfully");

	for (int i = 0; i < pManager->numberOfShapes(); i++)
		pManager->GetFigure(i)->setVisibility(true);
}