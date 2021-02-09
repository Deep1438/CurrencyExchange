#pragma once
#include"ErrorMessages.h"
#include"../CurrencyExchange/restCurl/CurlData.h"
#include"../CurrencyExchange/jsonParser/JSONData.h"

class CurrencyConverter {
	string m_currencyData;
	double m_resultValue;
	shared_ptr<APIRequestInterface> m_curlObj;
	shared_ptr<JSONRequestInterface> m_jsonObj;

public:
	CurrencyConverter();
	~CurrencyConverter();
	double convertCurrency(const float& amount, const string& baseCy, const string& targetCy, string& errorMsg);
	void setCurlObject(shared_ptr<APIRequestInterface>curlObj);
};