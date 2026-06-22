#pragma once
#include "clsScreen.h"
#include"clsUser.h"
#include"clsMainScreen.h"
#include "Globle.h"
#include "clsMainScreen.h"
#include "fstream"


class clsLoginScreen : protected clsScreen {


public:


	static bool _Login() {

		string UserName, Password;
		bool LoginFalied = false;

		short Tralis = 0;


		do {

			if (LoginFalied) {

				Tralis++;

				cout << "\nInvalid UserName / Password ! ";
				cout << "\nYou have got " << (3 - Tralis) << " Trali (s) To login";

			}

			if (Tralis == 3) {

				cout << "\n\n\nYou are locked after 3 Tralis ";
				return false;
			}

			cout << "\n\nEnter User Name : ";
			cin >> UserName;

			cout << "Enter password : ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFalied = CurrentUser.IsEmpty();

		} while (LoginFalied);

		CurrentUser.SaveLoginRecored();

		clsMainScreen::ShowMainMenue();

		

	}

public : 

	static bool Login() {

		

			system("cls");

			_DrawScreenHeader("\t\tLogin Screen");
			return _Login();

	
	}

	



};
