#include "ActionPlayByType.h"
#include "../ApplicationManager.h"
#include "../GUI/GUI.h"

ActionPlayByType::ActionPlayByType(ApplicationManager* pApp) :Action(pApp)
{
	correct = wrong = 0;

}


void ActionPlayByType::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	if (pManager->numberOfShapes() > 0) {
		string type = pManager->getRandomExistingType();
		int numberOfShapesOfType = pManager->countByType(type);

		pGUI->PrintMessage("Pick All Shapes of type " + type);
		while (numberOfShapesOfType > 0) {
			int x, y;
			pGUI->getPointInsideDrawArea(x, y);
			CFigure* fig = pManager->GetFigure(x, y);
			while (fig == NULL) {
				pGUI->PrintMessage("No Shape Found, Please Click on shape");
				pGUI->getPointInsideDrawArea(x, y);
				fig = pManager->GetFigure(x, y);
			}

			if (fig != NULL && fig->getShapeType() == type) {
				correct++;
				numberOfShapesOfType--;

			}
			else {
				wrong++;
			}

			fig->setVisibility(false);
			pManager->UpdateInterface();

			pGUI->PrintMessage("Correct: " + to_string(correct) + " || Wrong:" + to_string(wrong));
			if (numberOfShapesOfType == 0) {
				pGUI->PrintMessage("You Won ^_^ " + to_string(correct) + " / " + to_string(wrong));
			}
		}
	}
	else {
		pGUI->PrintMessage("There is no shapes");
	}
	for (int i = 0; i < pManager->numberOfShapes(); i++)
		pManager->GetFigure(i)->setVisibility(true);
	pManager->UpdateInterface();
}