#include"ErrorMessages.h"
#include"CurrencyConverter.h"

/// <summary>
/// Main Function for the user input and calling for further functionality  
/// </summary>
/// <returns>Return 0 on successful execution</returns>
int main()
{
	float amount = 0.0;
	string targetCurrency = "";
	string baseCurrency = "EUR"; /* Base currency is fixed for now i.e. EUR*/
	string errorMsg = "";
	double resultValue = 0.0;

	while (true) {
		errorMsg = "";
		cout << "Enter the amount : ";
		cin >> amount;

		if (amount < 0) {
			cout << Error::NEGATIVE_AMOUNT << endl;
			continue;
		}
		else if (amount == 0) {
			cout << Error::ZERO_AMOUNT << endl;
			continue;
		}
		//case needs to be added for char input

		cout << "Base currency (From) : " << baseCurrency << endl;
		//cin >> baseCurrency;          

		cout << "Enter the target Currency (To) : ";
		cin >> targetCurrency;
		transform(targetCurrency.begin(), targetCurrency.end(), targetCurrency.begin(), toupper);

		//read data by accessing API URL
		CurrencyConverter converter;
		//resultValue = converter.convertCurrency(amount, baseCurrency, targetCurrency, errorMsg);
		if (errorMsg != "")
		{
			cout << errorMsg << endl;
		}
		else {
			cout << "Currency Value of " << targetCurrency << " is : " << resultValue << endl;
		}

		char option;
		cout << endl;
		cout << "Want to Continue : (y/n)" << endl;
		cin >> option;
		option = toupper(option);

		switch (option) {
		case 'Y':
			cout << endl << endl;
			continue;
		case 'N':
			break;
		default:
			cout << "Invalid Option Selected" << endl;
			break;
		}
		break;
	}
	return 0;
}