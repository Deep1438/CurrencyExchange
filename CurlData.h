#pragma once
#include"APIRequestInterface.h"
#include"curl/curl.h"

class CurlData : public APIRequestInterface
{
	CURL* m_curlHandle;
	CURLcode m_res;               //curl result
	string m_currencyData;        //currency rates

public:
	CurlData();
	~CurlData();
	string executeAPIRequest(const string& baseCy, const string& targetCy, string& errorMsg) override;   //overriden method
	static size_t writeMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp);
};

