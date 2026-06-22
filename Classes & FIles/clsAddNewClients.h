#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"

class clsAddNewClients : protected clsScreen {


private:

	static void _ReadNewClientInfo(clsBankClient &Client) {

		cout << "\n\nEnter First Name ? ";
		Client.FirstName = clsInputValidate <string > ::ReadString();

		cout << "\nEnter Last Name ? ";
		Client.LastName = clsInputValidate <string > ::ReadString();

		cout << "\nEnter Phone Number ? ";
		Client.Phone = clsInputValidate <string > ::ReadString();

		cout << "\nEnter Email ? ";
		Client.Email = clsInputValidate <string > ::ReadString();

		cout << "\nEnter Pin Code ? ";
		Client.PinCode = clsInputValidate <string > ::ReadString();

		cout << "\nEnter Balance ? ";
		Client.AccountBalance = clsInputValidate <float  > ::ReadtNumber();



	}

	static void _PrintNewClientInof(clsBankClient Client) {

		
		cout << "\t\tClient Info";
		cout << "\n______________________________________" << endl;
		cout << "\nFirst Name   : " << Client.FirstName;
		cout << "\nLast Name    : " << Client.LastName;
		cout << "\nFull Name    : " << Client.FullName();
		cout << "\nPhone Number : " << Client.Phone;
		cout << "\nAcc.Number   : " << Client.AccountNumber();
		cout << "\nEmail        : " << Client.Email;
		cout << "\nPin Code     : " << Client.PinCode;
		cout << "\nBalacne      : " << Client.AccountBalance;
		cout << "\n______________________________________" << endl;


	}


public :

	static void ShowAddNewClients() {
		
		if (!_CheckAccessRights(clsUser::enPermissions::pAddNewClient)) {

			return;
		}

		_DrawScreenHeader("\t\tAdd New Clients");


		string AccountNumber = "";

		 cout << "\n\nPlease enter New Account Number ? " << endl;
		 AccountNumber = clsInputValidate <string >  ::ReadString();

		 while (clsBankClient::IsClientExist(AccountNumber)) {

			 cout << "This Account Number [" << AccountNumber << "] is Exists , Choose another one ! " << endl;
			 AccountNumber = clsInputValidate <string >  ::ReadString();

		 }

		 clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		 _ReadNewClientInfo(NewClient);
		 _PrintNewClientInof(NewClient);

		

		 clsBankClient::enSaveResults SaveResult;

		 SaveResult = NewClient.Save();

		 switch (SaveResult) {

		 case clsBankClient::enSaveResults::svSucceeded: {
			 cout << "\n\nClient added Successfully ";
			 break;

		 }

		 case clsBankClient::enSaveResults::svFaildAccountNumberExists: {
			 cout << "\n\nErorr , This Account Number is Exists ! ";
			 break;

		 }

		 case clsBankClient::enSaveResults::svFaildEmptyObject: {

			 cout << "\nError account was not saved because it's Empty";
			 break;
		 }

		 }
	}



};

