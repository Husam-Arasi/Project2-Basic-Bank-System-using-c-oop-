#pragma once

#include "clsUser.h"
#include "clsScreen.h"
#include "clsString.h"


class clsLoginRegisterScreen : protected clsScreen {


private :

	static void _PrintLoginRegisterRecored(clsUser::stLoginRegister LoginRegsiter) {

		cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegsiter.DateTime;
		cout << "| " << setw(20) << left << LoginRegsiter.UserName;
		cout << "| " << setw(20) << left << LoginRegsiter.Password;
		cout << "| " << setw(10) << left << LoginRegsiter.Permissions;



	}


public:

    static void ShowLoginRegisterScreen()
    {

        if (!_CheckAccessRights(clsUser::enPermissions::pLoginRegisterList)) {

            return;
        }

        vector <clsUser::stLoginRegister> vLoginRegisterRecord = clsUser::_LoadLoginRegisterDataFromFile();

        string Title = "\tLogin Register List Screen";
        string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsUser::stLoginRegister Record : vLoginRegisterRecord)
            {

                _PrintLoginRegisterRecored(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }




};
