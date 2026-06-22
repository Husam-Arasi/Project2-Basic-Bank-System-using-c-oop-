
#pragma once

#include <iostream>
#include "Globle.h"
#include "clsDate.h"

using namespace std;



class clsScreen {


protected: 

   
	static void _DrawScreenHeader(string Tital  = "This is the main Scrren", string SubTital = "") {

		cout << "\t\t\t\t\t____________________________________________\n\n";
		cout << "\t\t\t\t\t" << Tital << endl;
		

		if (SubTital != "") {

			cout << "\t\t\t\t\t" << SubTital << endl;
		}

		cout << "\t\t\t\t\t____________________________________________\n";

		DisplayDateUserName();

	}


	static bool _CheckAccessRights(clsUser::enPermissions Permissions) {

		if (!CurrentUser.CheckAccessPermissions(Permissions)) {

			_DrawScreenHeader("Access Denied ! please contect your Ademin");


			return false;

		}
		else
		{
			return true;
		}


	}


	static void DisplayDateUserName() {

		cout << "\n\n\t\t\t\tUserName : " << CurrentUser.UserName ;

		cout << "\n\n\t\t\t\tDate: " << clsDate::DateToString(clsDate::GetSystemDate()) << endl << endl;



	}



};

