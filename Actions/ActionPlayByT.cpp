#include "ِActionPlayBy.h"
#include "ActionPlayByT.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "CFigure.h"
#include <iostream>

ActionPlayByT::ActionPlayByT(ApplicationManager* pApp):ActionPlayBy(pApp) {};

void ActionPlayByT::Execute()
{

	cout << "Hello from the play type" << endl;
	GUI* pGUI = pManager->GetGUI();

	// start a new game if non is running
	if (ActionPlayBy::type != ACTION_PLAY_TYPE)
	{
		ActionPlayBy::type = ACTION_PLAY_TYPE;
		ActionPlayBy::correct = 0;
		ActionPlayBy::wrong = 0;
		ActionPlayBy::inGameType = "";

		if (pManager->numberOfShapes() == 0)
		{
			pGUI->PrintMessage("There is no shapes");
			ActionPlayBy::type = EMPTY;
		}
		else
		{
			ActionPlayBy::inGameType = pManager->getRandomExistingType();
			pGUI->PrintMessage("Pick All Shapes of type " + ActionPlayBy::inGameType);
		}
	}

	// continue the game
	else
	{
		int typeCount = pManager->countByType(inGameType);
		int x, y;
		pGUI->GetPointClicked(x, y);

		CFigure* fig = pManager->GetFigure(x, y);
		if (fig == NULL)
		{
			pGUI->PrintMessage("No Shape Found, Please Click on shape");
		}

		else if (fig->getShapeType() == ActionPlayBy::inGameType)
			ActionPlayBy::correct++;

		else
			ActionPlayBy::wrong++;

		if (fig != NULL)
			fig->setVisibility(false);

		pGUI->PrintMessage("Correct: " + to_string(ActionPlayBy::correct) + " || Wrong:" + to_string(ActionPlayBy::wrong));

		if (ActionPlayBy::correct == typeCount)
		{
			pGUI->PrintMessage("You Won ^_^ ");
		}
		else if(ActionPlayBy::wrong == 3)
		{
			pGUI->PrintMessage("You Lost *_* ");
		}

		if (ActionPlayBy::correct == typeCount || ActionPlayBy::wrong == 3)
		{
			ActionPlayBy::type = EMPTY;
			ActionPlayBy::correct = 0;
			ActionPlayBy::wrong = 0;
			ActionPlayBy::inGameType = "";

			for (int i = 0; i < pManager->numberOfShapes(); i++)
				pManager->GetFigure(i)->setVisibility(true);
		}


	}
}