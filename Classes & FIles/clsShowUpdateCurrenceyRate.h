#pragma once

#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"


class clsShowUpdateCurrenceyRate : clsScreen {

private:


	static void _PrintCurrencyCard(clsCurrency C1) {


		cout << "\nCurrency Card : ";
		cout << "\n_______________________________________";
		cout << "\nCountery         : " << C1.Country();
		cout << "\nCode             : " << C1.CurrencyCode();
		cout << "\nCurrency Name    : " << C1.CurrencyName();
		cout << "\nRate / ($1)      : " << C1.Rate();

		cout << "\n_______________________________________\n";


	}

	static float  _ReadToUpdateRate() {

		float Rate;

		cout << "\nEnter New Rate : ";
		Rate = clsInputValidate <float > ::ReadtNumber();

		return Rate;



	}



public :


	static void ShowUpdateRateScreen() {

		_DrawScreenHeader("\t\tUpdate Rate Screen ");


		string Code;

		cout << "\n\nPlease enter the Currency Code : ";
		Code = clsInputValidate <string >  ::ReadString();


		while (!clsCurrency::IsCurrencyExistByCode(Code)) {
			
			cout << "\nInvalid Code , Try again : ";
			Code = clsInputValidate <string >  ::ReadString();

		}

		clsCurrency C1 = clsCurrency::FindByCode(Code);

		_PrintCurrencyCard(C1);


		char Answer = 'n';

		cout << "\n\nAre you sure you want to update the Currency Rate  y/n ? ";
		cin >> Answer;

		if (toupper(Answer)) {

			cout << "\n\nUpdate Rate  : ";
			cout << "\n_______________________________________";

			
			C1.UpdateRate(_ReadToUpdateRate());

			cout << "\n\nCurrency Rate has been updated successfully -:) ";
			_PrintCurrencyCard(C1);

		

		}
		else {
			cout << "Eorror , Can't be save please try agian ! ";
		}







	}








};

