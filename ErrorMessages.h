#pragma once
#include <iostream>
#include <algorithm>
#include "string"
using namespace std;

namespace Error
{
	const static string NEGATIVE_AMOUNT = "Error : Please enter a positive value";
	const static string ZERO_AMOUNT = "Error : Amount must be greater than 0";
	const static string SERVER_NOT_RESPONDING = "Curl Error : Unable to obtain information";
	const static string PARSE_INFO_NOT_FOUND = "JSON Parsing Error : Country Code mapping not found";
	const static string PARSE_NOT_SUCCESS = "JSON Syntax Error : Value, Object or Array expected";
}
