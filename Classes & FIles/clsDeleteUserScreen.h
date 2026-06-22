#pragma once

#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen {

private:

	static void _PrintUserInfo(clsUser User) {

		cout << "\n\nUser Inof " << endl;
		cout << "------------------------";
		cout << "\nFirst Name : " << User.FirstName;
		cout << "\nLast Name : " << User.LastName;
		cout << "\nFull Name : " << User.FullName();
		cout << "\nEmail : " << User.Email;
		cout << "\nPhone Number : " << User.Phone;
		cout << "\nUser Name : " << User.UserName;
		cout << "\nPassword : " << User.Password;
		cout << "\nPermisstions : " << User.Permissions;
		cout << "\n------------------------\n\n";

	}

public :

	static void ShowDeleteUserScreen() {

		_DrawScreenHeader("\tDelete User Screen");

		string UserName;

		cout << "\nPlease enetr the user name that you want to delete it ? ";
		UserName = clsInputValidate <string >  ::ReadString();

		while (!clsUser::IsUserExist(UserName)) {
			cout << "\nThis user name is't exits , enter invalid user name ? ";
			UserName = clsInputValidate <string >  ::ReadString();
		}

		clsUser User =  clsUser::Find(UserName);

		_PrintUserInfo(User);

		char Answer = 'n';

		cout << "\n\nAre you sure you want to delete this user ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {

			if (User.Delete()) {
				_PrintUserInfo(User);

			cout << "\n\nUser has been deleted sccussfully !";
			}

		else {

			cout << "\n\nErorr the User has't been deleted !  ";
		}

		}

	}



};
