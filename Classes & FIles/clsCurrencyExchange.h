#pragma once

#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsShowCurrencyList.h"
#include "clsShowFindCurrencyScreen.h"
#include "clsShowUpdateCurrenceyRate.h"
#include "clsCurrenceyCalcalator.h"


using namespace std;


class clsCurrencyExchange : protected clsScreen {


	enum enCurrencyExchangeMenue { eListCurrency = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrenceyCulacluator = 4, eExit = 5 };



	static void _ShowListCurrency() {
           
		clsShowCurrencyList::ShowListCurreneiesScreen();
		
	}

    static 	void _ShowFindCurrency() {
		clsShowFindCurrencyScreen::ShowFindCurrencyScreen();
		

	}

	 static void _ShowUpdatRate() {
		 clsShowUpdateCurrenceyRate::ShowUpdateRateScreen();
		
	}


	static void _ShowCulacluatorCurrencey() {
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	

	static void _BackToMainMeneu() {

		cout << "\n\nPress any key to go back to Currencies Menue...";
		system("pause > 0 ");
		ShowExchageCurrencyMeneu();


	}


static	short _ReadCurrenceyExhchageMeneu() {


 	    cout << "\t\t\t\tPlease Select  a number between [1] to [5] ? ";
		short Choies = clsInputValidate <short > ::ReadNumberBetween(1, 5, "\nInvalid Number , Enter a number between [1] to [5] ? ");

		return Choies;

	}


	static void _PerforeCurrecneyExchangeMeneu(enCurrencyExchangeMenue CurrencyMeneu) {

		switch (CurrencyMeneu) {

		case enCurrencyExchangeMenue::eListCurrency: {

			system("cls");
			_ShowListCurrency();
			_BackToMainMeneu();
			break;

		}
		case enCurrencyExchangeMenue::eFindCurrency: {

			system("cls");
			_ShowFindCurrency();
			_BackToMainMeneu();
			break;

		}
		case enCurrencyExchangeMenue::eUpdateRate: {

			system("cls");
			_ShowUpdatRate();
			_BackToMainMeneu();
			break;

		}

		case  enCurrencyExchangeMenue::eCurrenceyCulacluator: {
		
			system("cls");
			_ShowCulacluatorCurrencey();
			_BackToMainMeneu();
			break;

		}

		case enCurrencyExchangeMenue::eExit: {

		
		
			
		}




		}




	}


	public :


		static void ShowExchageCurrencyMeneu() {

			system("cls");
			_DrawScreenHeader("\t\tExchage Meneu Screen");

			

			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t\t\tExchage Meneu\n";
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t[1] List Currenceies.\n";
			cout << setw(37) << left << "" << "\t[2] Find Currencey.\n";
			cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
			cout << setw(37) << left << "" << "\t[4] Currencey Calcalutor .\n";
			cout << setw(37) << left << "" << "\t[5] Main Meneu .\n";
			cout << setw(37) << left << "" << "===========================================\n";

			_PerforeCurrecneyExchangeMeneu(enCurrencyExchangeMenue(_ReadCurrenceyExhchageMeneu()));






		}








};

