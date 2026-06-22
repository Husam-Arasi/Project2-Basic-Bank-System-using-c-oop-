#pragma once

#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsShowFindCurrencyScreen : protected clsScreen {


private:


	enum enOptions {ByCode = 1, ByCountery = 2 };


	static void _PrintCurrencyCard(clsCurrency C1 ) {


		cout << "\nCurrency Card : ";
		cout << "\n_______________________________________";
		cout << "\nCountery         : " << C1.Country();
		cout << "\nCode             : " << C1.CurrencyCode();
		cout << "\nCurrency Name    : " << C1.CurrencyName();
		cout << "\nRate / ($1)      : " << C1.Rate();

		cout << "\n_______________________________________\n";


	}

	static short _ReadTowOptions() {


		short Choise;

		cout << "\n\nFind By [1] Code or [2] Countery ? ";
		Choise = clsInputValidate <short> ::ReadNumberBetween(1, 2, "\nInvalid number , choise between [1] or [2] ");

		return Choise;



	}


	static void _SearchByCode() {


		string Code;


		cout << "\nPlease enter Code : ";
		Code = clsInputValidate <string >  ::ReadString();

		while (!clsCurrency::IsCurrencyExistByCode(Code)) {

			cout << "\nThis Code does't exists , Choise another one : ";
			Code = clsInputValidate <string >  ::ReadString();

		}

		clsCurrency C1 = clsCurrency::FindByCode(Code);

		if (C1.IsCurrencyExistByCode(Code)) {
			cout << "\n\nCurrency Found -:) " <<endl;
		
		   _PrintCurrencyCard(C1);
		
		}
		else
		{
			cout << "\n\nErorr Curency does't Exists ! ";

		}

		

	}

	static void _SearchByCountery() {


		string Countery;


		cout << "\nPlease enter Countery : ";
		Countery = clsInputValidate <string >  ::ReadString();

		while (!clsCurrency::IsCurrencyExistByCountery(Countery)) {

			cout << "\nThis Countery does't exists , Choise another one : ";
			Countery = clsInputValidate <string >  ::ReadString();

		}


		clsCurrency C1 = clsCurrency::FindByCountry(Countery);

		if (C1.IsCurrencyExistByCountery(Countery)) {
			cout << "\n\nCurrency Found -:) " << endl;

			_PrintCurrencyCard(C1);

		}
		else
		{
			cout << "\n\nErorr Curency does't Exists ! ";

		}



	}

	static void _PerferOptions(enOptions Options) {

		

		switch (Options) {

		case enOptions::ByCode :
			_SearchByCode();
			break;

		case enOptions::ByCountery:
			_SearchByCountery();
			break;

		}

	}


	public :

		static void ShowFindCurrencyScreen() {

			_DrawScreenHeader("\t\tFind Currency Scrren");

			_PerferOptions(enOptions(_ReadTowOptions()));

		}

};

