#pragma once
#include"json/json.h"
#include"ErrorMessages.h"
#include"JSONRequestInterface.h"

class JSONData : public JSONRequestInterface
{
		double targetCyValue;
	public:
		JSONData();
		~JSONData();
		double executeJSONParseRequest(const string& currencyData, const string& targetCy, string& errorMsg) override;
};

