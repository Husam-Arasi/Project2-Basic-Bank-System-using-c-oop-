#pragma once

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferLogScreen : protected clsScreen {


private :


    static void _PrintLoginRegisterRecored(clsBankClient::stTransferLog TrasnferLog) {

        cout << setw(8) << left << "" << "| " << setw(28) << left << TrasnferLog.DateTime;
        cout << "| " << setw(13) << left << TrasnferLog.SourseAccount;
        cout << "| " << setw(13) << left << TrasnferLog.DestinationAccount;
        cout << "| " << setw(10) << left << TrasnferLog.Amount;
        cout << "| " << setw(10) << left << TrasnferLog.SourseBalance;
        cout << "| " << setw(10) << left << TrasnferLog.DestinationBalance;
        cout << "| " << setw(10) << left << TrasnferLog.UserName;

    }


public:

    static void ShowLoginRegisterScreen()
    {

    

        vector <clsBankClient::stTransferLog> vTransferLog = clsBankClient::GetTransferLogHistory();

        string Title = "\tTransfer Log Screen";
        string SubTitle = "\t\t(" + to_string(vTransferLog.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(28) << "Date/Time";
        cout << "| " << left << setw(13) << "S.Account";
        cout << "| " << left << setw(13) << "D.Account";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "S.Balance";
        cout << "| " << left << setw(10) << "D.Balance";
        cout << "| " << left << setw(10) << "User Name";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________________\n" << endl;

        if (vTransferLog.size() == 0)
            cout << "\t\t\t\tNo Transfer Log  Available In the System!";
        else

            for (clsBankClient::stTransferLog Record : vTransferLog)
            {

                _PrintLoginRegisterRecored(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________________\n" << endl;


    }





};
