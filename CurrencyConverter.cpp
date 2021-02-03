#include"CurrencyConverter.h"

/// <summary>
/// Constructor
/// </summary>
CurrencyConverter::CurrencyConverter()
{
	m_currencyData = "";
	m_resultValue = 0.0;
	m_curlObj = unique_ptr<APIRequestInterface>(new CurlData());
}

/// <summary>
/// Destructor 
/// </summary>
CurrencyConverter :: ~CurrencyConverter()
{

}

/// <summary>
/// Method to convert one currency value to other currency
/// </summary>
/// <param name="amount">Value</param>
/// <param name="baseCy">Base Currency code(From)</param>
/// <param name="targetCy">Target Currency code(To)</param>
/// <param name="errorMsg">Error Message</param>
/// <returns>Calculated Target Currency value</returns>
double CurrencyConverter::convertCurrency(const float& amount, const string& baseCy, const string& targetCy, string& errorMsg)
{
	m_currencyData = m_curlObj->executeAPIRequest(baseCy, targetCy, errorMsg);
	return 0; //Need to modify
}
