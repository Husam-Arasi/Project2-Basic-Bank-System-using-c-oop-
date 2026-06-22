#pragma once

#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<iostream>


class clsWithDrawScreen : protected clsScreen {

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

    static void ShowWithDrawScreen() {

        _DrawScreenHeader("\t\tWithDraw Screen");


        string AccountNumber = " ";

        cout << "\n\nPlease enter the account numbe that you want to withdraw ? " << endl;

        AccountNumber = clsInputValidate <string >  ::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {

            cout << "This account number [" << AccountNumber << "] is exits , choose anther one ? " << endl;
            AccountNumber = clsInputValidate <string >  ::ReadString();


        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClient(Client);




        double WithDrawAmount = 0;


        do {
            cout << "\n\nEnter the amount you want to withdraw: ";
            WithDrawAmount = clsInputValidate < double > ::ReadtNumber();

            if (WithDrawAmount >= Client.AccountBalance || WithDrawAmount <= 0 ) {
                cout << "\nCan't withdraw, Insufficient Balance!";
                cout << "\nAmount to withdraw = " << WithDrawAmount;
                cout << "\nYour balance = " << Client.AccountBalance;
            }

        } while (WithDrawAmount <= 0 || WithDrawAmount > Client.AccountBalance);



            char Answer = ' ';

            cout << "\nAre you sure you want to withdraw this amount ? " << endl;

            cin >> Answer;

            if (Answer == 'y' || Answer == 'Y') {

                if (Client.Withdraw(WithDrawAmount)) {
                    cout << "\nWithdraw has been done successfully ";
                    cout << "\nNew Balance is = " << Client.AccountBalance;
                }
                else
                {
                    cout << "\nEorro , can't withdraw ! " << endl;
                }


            }





        }





 

};


