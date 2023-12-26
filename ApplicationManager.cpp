#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include "ActionAddElipse.h"
#include "ActionSelect.h"
#include <iostream>


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;
}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{		
		//1- Read user action
		ActType = pGUI->MapInputToActionType();
		
		//2- Create the corresponding Action
		Action *pAct = CreateAction(ActType);
		
		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface
		UpdateInterface();	

	}while(ActType != EXIT);
	
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	cout << "ActType: " << ActType << endl;
	Action* newAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_SQUARE:
			newAct = new ActionAddSquare(this);
			break;

		case DRAW_ELPS:
			newAct = new ActionAddElipse(this);
			///create AddLineAction here

			break;

		case DRAWING_AREA:
			//pGUI->PrintMessage("Drawing Mode baby!");
			//pGUI->ClearStatusBar();
			int x, y;
			pGUI->GetPointClicked(x, y);
			newAct = new ActionSelect(this, { x,y });

		case EXIT:
			///create ExitAction here
			break;

		case TO_PLAY:
			pGUI->PrintMessage("play mode baby");
			pGUI->CreatePlayToolBar();
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;

		case ACTION_TO_DRAW:
			pGUI->PrintMessage("back to Draw!");
			pGUI->CreateDrawToolBar();
			break;

		case ACTION_PLAY_TYPE:
			pGUI->PrintMessage("ACTION_PLAY_TYPE");
			break;

		case ACTION_PLAY_FILL:
			pGUI->PrintMessage("ACTION_PLAY_FILL");
			break;

		case ACTION_PLAY_TYPEFILL:
			pGUI->PrintMessage("ACTION_PLAY_TYPEFILL");
			break;

		case ACTION_PLAY_RESET:
			pGUI->ClearStatusBar();
			break;

	}	
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{

	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->ContainPoint(x, y))
			return FigList[i];	
	}
	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pGUI->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->DrawMe(pGUI);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pGUI;
	
}
