#pragma once
#include"../ErrorMessages.h"

class JSONRequestInterface {
	public:
		virtual ~JSONRequestInterface() = default;
		virtual double executeJSONParseRequest(const string& currencyData, const string& targetCy, string& errorMsg) = 0;  //for currency Data
};
