#pragma once
#include"json/json.h"
#include"../../CurrencyExchange/interfaces/JSONRequestInterface.h"

class JSONData : public JSONRequestInterface
{
		double targetCyValue;
	public:
		JSONData();
		~JSONData();
		double executeJSONParseRequest(const string& currencyData, const string& targetCy, string& errorMsg) override;
};

