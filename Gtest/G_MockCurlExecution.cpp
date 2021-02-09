#include "pch.h"
#include "G_MockCurlInterface.h"
#include "../CurrencyExchange/CurrencyConverter.h"

using ::testing::_;
using ::testing::Test;

class RestUsingCurlTest : public testing::Test
{
public:
	// Per-test-suite set-up.
	// Called before the first test in this test suite.
	// Can be omitted if not needed.
	static void SetUpTestSuite()
	{

	}

	// Per-test-suite tear-down.
	// Called after the last test in this test suite.
	// Can be omitted if not needed.
	static void TearDownTestSuite()
	{

	}

	// You can define per-test set-up logic as usual.
	virtual void SetUp()
	{
		m_curlObj = make_shared<MockCurlInterface>();
		converterObj.setCurlObject(m_curlObj);
		errorMsg = "";
	}

	// You can define per-test tear-down logic as usual.
	virtual void TearDown()
	{

	}

protected:
	CurrencyConverter converterObj;
	shared_ptr<MockCurlInterface> m_curlObj;
	string errorMsg;
};

TEST_F(RestUsingCurlTest, conversionFactorTest)
{
	// To prevent actual curl request, mock curl proxy
	ON_CALL(*m_curlObj, executeAPIRequest).WillByDefault([](const string& from, const string& to, string& errorMsg) {
		return std::string("{\
			\"success\":true,\
			\"timestamp\" : 1607599745,\
			\"base\" : \"EUR\",\
			\"date\" : \"2021-02-07\",\
			\"rates\" : {\
			\"USD\":1.204905\
			}\
			}");
		});
	EXPECT_CALL(*m_curlObj, executeAPIRequest(_, _, _)).Times(1);

	auto conversionFactor = converterObj.convertCurrency(1, "EUR", "USD", errorMsg);
	EXPECT_EQ(conversionFactor, 1.204905);
	EXPECT_STREQ("", errorMsg.c_str());
}

TEST_F(RestUsingCurlTest, incorrectValueReceivedTest)
{
	// To prevent actual curl request, mock curl proxy
	ON_CALL(*m_curlObj, executeAPIRequest).WillByDefault([](const string& from, const string& to, string& errorMsg) {
		return std::string("{\
			\"success\":true,\
			\"timestamp\" : 1607599745,\
			\"base\" : \"EUR\",\
			\"date\" : \"2021-02-07\",\
			\"rates\" : {\
			\"USD\": XXX1.204905\
			}\
			}");
		});
	EXPECT_CALL(*m_curlObj, executeAPIRequest(_, _, _)).Times(1);

	auto conversionFactor = converterObj.convertCurrency(1, "EUR", "USD", errorMsg);
	EXPECT_EQ(conversionFactor, 0.0);
	EXPECT_STREQ((Error::PARSE_NOT_SUCCESS).c_str(), errorMsg.c_str());
}

TEST_F(RestUsingCurlTest, incorrectCurrencyCodeDefined)
{
	// To prevent actual curl request, mock curl proxy
	ON_CALL(*m_curlObj, executeAPIRequest).WillByDefault([](const string& from, const string& to, string& errorMsg) {
		return std::string("{\
			\"success\":false,\
			\"error\" : {\
			\"code \" : 202,\
			\"type\" : \"invalid_currency_codes\",\
			\"info\" : \"You have provided one or more invalid Currency Codes. [Required format: currencies=EUR,USD,GBP,...]\"\
			}\
			}");
		});
	EXPECT_CALL(*m_curlObj, executeAPIRequest(_, _, _)).Times(1);

	auto conversionFactor = converterObj.convertCurrency(2, "EUR", "XXX", errorMsg);
	EXPECT_EQ(conversionFactor, 0.0);
	EXPECT_STREQ((Error::PARSE_INFO_NOT_FOUND).c_str(), errorMsg.c_str());
}

TEST_F(RestUsingCurlTest, conversionFactorEmptyStringTest)
{
	// To prevent actual curl request, mock curl proxy
	ON_CALL(*m_curlObj, executeAPIRequest).WillByDefault([](const string& from, const string& to, string& errorMsg) {
		return std::string("");
		});
	EXPECT_CALL(*m_curlObj, executeAPIRequest(_, _, _)).Times(1);

	auto conversionFactor = converterObj.convertCurrency(2, "EUR", "USD", errorMsg);
	EXPECT_EQ(conversionFactor, 0.0);
	EXPECT_STREQ((Error::PARSE_NOT_SUCCESS).c_str(), errorMsg.c_str());
}
