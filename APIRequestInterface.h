#pragma once
#include"ErrorMessages.h"

class APIRequestInterface {

public:
	virtual ~APIRequestInterface() = default;
	virtual string executeAPIRequest(const string& baseCy, const string& targetCy, string& errorMsg) = 0;  //Pure Virtual Function 
};