#pragma once
#include "clsUser.h"
#include"clsScreen.h"
#include "clsInputValidate.h"



class clsFindUserScreen : protected clsScreen {

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
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

    static void ShowFindUserScreen() {
   
        
        _DrawScreenHeader("\tFind User Screen ");

        string UserName;

        cout << "\nPlease enter the user that you want to search it ? ";
        UserName = clsInputValidate <string >  ::ReadString();


        while (!clsUser::IsUserExist(UserName)) {

            cout << "\nUser Name does't exits , try again ! ";
            UserName = clsInputValidate <string >  ::ReadString();

        }

        clsUser User = clsUser::Find(UserName);


        _PrintUser(User);


        

    }


};
