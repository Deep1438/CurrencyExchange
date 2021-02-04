#include "JSONData.h"

/// <summary>
/// Constructor
/// </summary>
JSONData::JSONData()
{
    targetCyValue = 0.0;
}

/// <summary>
/// Destructor
/// </summary>
JSONData :: ~JSONData()
{

}

/// <summary>
/// Function to execute JSON parsing request for currency rate
/// </summary>
/// <param name="currencyData">json string</param>
/// <param name="targetCy">Target Currency</param>
/// <param name="errorMsg">Refrence of error message</param>
/// <returns>Parsed currency rate</returns>
double JSONData::executeJSONParseRequest(const string& currencyData, const string& targetCy, string& errorMsg)  //for currency Data
{
    Json::Reader reader;
    Json::Value root;   //main object
    string ratesTag{ "rates" };

    bool parseSuccess = reader.parse(currencyData, root, false);   //converting a string data {currencyData} into a json::value {root} i.e. json object

    if (!parseSuccess) {
        errorMsg = Error::PARSE_NOT_SUCCESS;
    }
    else {
        const Json::Value resultValue = root[ratesTag][targetCy];
        if (resultValue.isNull()) {
            errorMsg = Error::PARSE_INFO_NOT_FOUND;
        }
        else {
            targetCyValue = resultValue.asDouble();
        }
    }
    return targetCyValue;
}
