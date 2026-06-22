#pragma once

#include <iostream>
#include "clsScreen.h"
#include  "clsInputValidate.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"




class clsMangeUsersMenue : protected clsScreen {



private :


	enum enMangeUsersOptions {ListUser = 1 , AddUser = 2 , DeleteUser = 3 , UpdateUser = 4 , FindUser = 5,Exit = 6 };

	static void _ShowListUserScreen() {

		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAddUserScreen() {
		clsAddNewUserScreen::ShowAddNewUserScreen();

	}

	static void _ShowDeleteUserScreen() {
		
		clsDeleteUserScreen::ShowDeleteUserScreen();

	}

	static void _ShowUpdateUserScreen() {
		clsUpdateUserScreen::ShowUpdatUserScreen();

	}

	static void _ShowFindUserScreen() {
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void  _ShowExitScreen() {

		char Answer = ' ';

		cout << "\nThis page is for Exit the program  , \n\nAre you sure you want to exit the program ?  ";
		cin >> Answer;



		if (Answer == 'y' || Answer == 'Y') {

			return;

		}

		else {
		
			ShowMangeUsersManue();

		}




	}

	static void _BackToMangeUsersMeneu() {

			cout << "\n\nPress any key to go back to Manage Users Menu...";
			system("pause >0 ");
			ShowMangeUsersManue();


	 }


	static short _ReadMangeUsersOptions() {

		short Choose = 0;

		cout << "\n\nChoose what do you want to do? [1 to 6]? ";
		Choose = clsInputValidate <short > ::ReadNumberBetween(1, 6, "\nInvalid Number , try again by using from 1 to 6 option");


		return Choose;



	}




	static  void _PerformMangeUsersMenue(enMangeUsersOptions MangeUsersOptions) {


		


		switch (MangeUsersOptions) {

		case enMangeUsersOptions::ListUser: {

			system("cls");
			_ShowListUserScreen();
			_BackToMangeUsersMeneu();

			break;
		}
		case enMangeUsersOptions::AddUser: {

			system("cls");
			_ShowAddUserScreen();
			_BackToMangeUsersMeneu();

			break;

		}

		case enMangeUsersOptions::DeleteUser: {

			system("cls");
			_ShowDeleteUserScreen();
			_BackToMangeUsersMeneu();

			break;

		}

		case enMangeUsersOptions::UpdateUser: {

			system("cls");
			_ShowUpdateUserScreen();
			_BackToMangeUsersMeneu();

			break;

		}

		case enMangeUsersOptions::FindUser: {

			system("cls");
			_ShowFindUserScreen();
			_BackToMangeUsersMeneu();

			break;

		}

		case enMangeUsersOptions::Exit: {

			system("cls");
			_ShowExitScreen();
			

			break;
			

		}


		}


	}
	



public :


	static void ShowMangeUsersManue()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pManageUsers)) {

			return;
		}


		system("cls");
		_DrawScreenHeader("\t\tMange Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMange Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Users List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Usert.\n";
		cout << setw(37) << left << "" << "\t[4] Update User Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformMangeUsersMenue(enMangeUsersOptions(_ReadMangeUsersOptions()));

		
	}







};


