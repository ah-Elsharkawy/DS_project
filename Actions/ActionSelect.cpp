#include "ActionSelect.h"
#include <iostream>

using namespace std;

ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{
	//multiSelect = _multiSelect;
	P;
}

void ActionSelect::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	//check where this point :
	//and return selected figure or null
	pGUI->GetPointClicked(P.x, P.y);
	std::cout << P.x << " " << P.y << endl;
	CFigure* fig = pManager->GetFigure(P.x, P.y);
	// no figure selected
	if (fig == NULL)
	{
		pGUI->PrintMessage("No Figure Selected");
		//pGUI->ClearStatusBar();
		//pManager->UnSelectFigures(2);
	}
	else
	{
		//cout << "fig->IsSelected() = " << fig->IsSelected() << endl;
		if (!fig->IsSelected())
		{
			pGUI->PrintMessage("figure selected");
			fig->SetSelected(true);

			//cout << "fig->IsSelected() = " << fig->IsSelected() << endl;
		}
		else
		{

			pGUI->PrintMessage("figure unselected");
			fig->SetSelected(false);

		}
	}
}
