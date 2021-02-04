#pragma once
#include"ErrorMessages.h"
#include"CurlData.h"
#include"JSONData.h"

class CurrencyConverter {
	string m_currencyData;
	double m_resultValue;
	unique_ptr<APIRequestInterface> m_curlObj;
	unique_ptr<JSONRequestInterface> m_jsonObj;

public:
	CurrencyConverter();
	~CurrencyConverter();
	double convertCurrency(const float& amount, const string& baseCy, const string& targetCy, string& errorMsg);
};