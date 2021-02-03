#include "CurlData.h"

/// <summary>
/// Constructor
/// </summary>
CurlData::CurlData()
{
	m_curlHandle = curl_easy_init();
	m_res = CURLE_OK;
	m_currencyData = "";
}

/// <summary>
/// Destructor
/// </summary>
CurlData :: ~CurlData()
{
	curl_easy_cleanup(m_curlHandle);
	m_curlHandle = nullptr;
	curl_global_cleanup();
}

/// <summary>
/// Function to execute the curl request
/// </summary>
/// <param name="baseCy">Base Currency code</param>
/// <param name="targetCy">Target Currency code</param>
/// <param name="errorMsg">Reference to error message</param>
/// <returns>JSON string</returns>
string CurlData::executeAPIRequest(const string& baseCy, const string& targetCy, string& errorMsg)
{
	if (m_curlHandle) {
		string path = "http://data.fixer.io/api/latest?access_key=f2efe7207738bb66b7a61ac329140ef5&symbols=" + targetCy + "&format=1";
		curl_easy_setopt(m_curlHandle, CURLOPT_URL, path.c_str());
		curl_easy_setopt(m_curlHandle, CURLOPT_WRITEFUNCTION, writeMemoryCallback);
		curl_easy_setopt(m_curlHandle, CURLOPT_WRITEDATA, &m_currencyData);
		m_res = curl_easy_perform(m_curlHandle);
		if (m_res != CURLE_OK) {
			errorMsg = Error::SERVER_NOT_RESPONDING;
		}
	}
	return m_currencyData;
}

/// <summary>
/// Callback function for CURLOPT_WRITEFUNCTION
/// </summary>
/// <param name="contents">Received data</param>
/// <param name="size">Size of each member</param>
/// <param name="nmemb">Number of members</param>
/// <param name="userp">User reply</param>
/// <returns>Size of reply</returns>
size_t CurlData::writeMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	auto retVal = size * nmemb;
	if (!retVal)
		return 0;
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return static_cast<int>(size * nmemb);
}
