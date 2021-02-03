#pragma once
#include"ErrorMessages.h"
#include"CurlData.h"

class CurrencyConverter {
	string m_currencyData;
	double m_resultValue;
	unique_ptr<APIRequestInterface> m_curlObj;

public:
	CurrencyConverter();
	~CurrencyConverter();
	double convertCurrency(const float& amount, const string& baseCy, const string& targetCy, string& errorMsg);
};