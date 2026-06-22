#pragma once

#include "clsCurrency.h"
#include "clsScreen.h"	
#include "iomanip"
using namespace std;

class clsShowCurrencyList : protected clsScreen {


private :


	static void _PrintCurrencyCard(clsCurrency Currency) {


		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();

	}


public :

	static void ShowListCurreneiesScreen() {

		vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();

		string Tital = "\t\tList Courrenies Screen";
		string SubTital = "\t(" + to_string(vCurrency.size()) + ") Currency(s).";

		_DrawScreenHeader(Tital, SubTital);


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Countery Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;


		if (vCurrency.size() == 0) 
			cout << "\n\nNo Currenies avalible now in the system !" << endl;

		else
		
			for (clsCurrency& C1 : vCurrency) {

				_PrintCurrencyCard(C1);
				cout << endl;
			}
	
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;







	}




};