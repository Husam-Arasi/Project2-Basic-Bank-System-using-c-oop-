#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsFindClientScreen : protected clsScreen {

private :



    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }



public :

   

    static void ShowFindClientScreen() {


        if (!_CheckAccessRights(clsUser::enPermissions::pFindClient)) {

            return;
        }


        _DrawScreenHeader("\tFind Client Screen");


        string AccountNumber = " ";


        cout << "\n\nPlease enter the Account Number that you want to Find ? " << endl;
        AccountNumber = clsInputValidate <string >  ::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {

            cout << "Account Number [" << AccountNumber << "] is not exists , try to enter another one ? " << endl;
            AccountNumber =  clsInputValidate <string >  ::ReadString();

        }


        clsBankClient Client = clsBankClient::Find(AccountNumber);


        if (!Client.IsEmpty()) {

            cout << "\n\nClient Found :-)\n\n  ";


        }
        else {

            cout << "\n\nClient was not Found \n\n ";

        }


        _PrintClient(Client);
        



    }


    





};

