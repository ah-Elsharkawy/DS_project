#pragma once

#include "ِActionPlayBy.h"


// ... rest of the implementation

class ApplicationManager;
class ActionPlayBy;

class ActionPlayByT: public ActionPlayBy
{

public:
	ActionPlayByT(ApplicationManager* pApp);

	void Execute();
};