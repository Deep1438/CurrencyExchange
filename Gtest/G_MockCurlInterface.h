#pragma once
#include"pch.h"
#include"../../CurrencyExchange/interfaces/APIRequestInterface.h"

class MockCurlInterface : public APIRequestInterface {
public:
	MOCK_METHOD(std::string, executeAPIRequest, (const string& baseCy, const string& targetCy, string& errorMsg), (override));
};