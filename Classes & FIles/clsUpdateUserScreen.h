#pragma once

#include "clsUser.h"
#include "clsInputValidate.h"
#include"clsScreen.h"


class clsUpdateUserScreen : protected clsScreen {

private:

	static void _ReadUserInfoToUpdate(clsUser &User) {


		cout << "\nFirst Name ? ";
		User.FirstName = clsInputValidate <string >  ::ReadString();

		cout << "\nLast Name ? ";
		User.LastName = clsInputValidate <string >  ::ReadString();

		cout << "\nEmail ? ";
		User.Email = clsInputValidate <string >  ::ReadString();

		cout << "\nPhone Number ? ";
		User.Phone = clsInputValidate <string >  ::ReadString();

		cout << "\nPassword ? ";
		User.Password = clsInputValidate <string >  ::ReadString();

		cout << "\nPermisstions ? ";
		User.Permissions = _ReadPermissionsToSet();




	}


    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }


        cout << "\nShow Login Registers List  ? y/n ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            Permissions += clsUser::enPermissions::pLoginRegisterList;
        }

        cout << "\nShow Transfer Log List ? y/n ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            Permissions += clsUser::enPermissions::pTransferLog;
        }

        return Permissions;

    }



    static void _PrintUserInfo(clsUser User)
    {
        cout << "\n\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }


    public :

        static void ShowUpdatUserScreen() {


            _DrawScreenHeader("\tUpdate User Screen");

            string UserName;

            cout << "\nPlease enter the user name that you want to update ? ";
            UserName = clsInputValidate <string >  ::ReadString();

            while (!clsUser::IsUserExist(UserName)) {
                cout << "\nUser Name not found , choose anther one ? ";
                UserName = clsInputValidate <string >  ::ReadString();

            }

            clsUser User = clsUser::Find(UserName);

            _PrintUserInfo(User);

            char Answer = 'n';

            cout << "\n\nAre you sure you want to update this user's info ? ";
            cin >> Answer;

            if (Answer == 'y' || Answer == 'Y') {

                cout << "\n\nUpdate Client Info:";
                cout << "\n____________________\n";


                _ReadUserInfoToUpdate(User);



            clsUser::enSaveResults Results;

            Results = User.Save();

            switch (Results) {

            case clsUser::enSaveResults::svSucceeded: {

                cout << "\n\nUser has been updated sccessfully ! ";
                _PrintUserInfo(User);
                break;
            }
             
            case clsUser::enSaveResults::svFaildEmptyObject: {

                cout << "\n\nUser is empty ! ";

                break;

            }


        }
            }




            }

};
