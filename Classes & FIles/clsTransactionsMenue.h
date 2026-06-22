#pragma once

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsDepositeScreen.h"
#include "clsWithDrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include  "clsTransferMoneyScreen.h"
#include "clsTransferLogScreen.h"



class clsTransactionsMenue :protected clsScreen {


private:

	enum enTransactionsOptions { Deposite = 1, WithDraw = 2, TotalBalance = 3, Transfer = 4 , TransferLog = 5 , Exit = 6 };

    static short _ReadTransactionsMenueOption() {

        cout << "\n\nChoose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate <short > ::ReadNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;

    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowTransactionsMenueScreen();
    }

    static void _ShowDepositeScreen() {
       
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithDrawScreen() {
       
        clsWithDrawScreen::ShowWithDrawScreen();

    }

    static void _ShowTotalBalanceScreen() {
        
        clsTotalBalancesScreen::ShowTotalBalances();

    }

    static void _ShowTransferScreen() {

       clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLog() {

        clsTransferLogScreen::ShowLoginRegisterScreen();
    }

    static void _ShowExitScreen() {
       
       
    }


    static  void _PerformTransactionsMenue(enTransactionsOptions TransactionsOptions) {

        switch (TransactionsOptions) {

        case enTransactionsOptions::Deposite: {
            
            system("cls");
            _ShowDepositeScreen();
            _GoBackToMainMenue();
            break;
        }
        case enTransactionsOptions::WithDraw: {

            system("cls");
            _ShowWithDrawScreen();
            _GoBackToMainMenue();
            break;
        }
        case enTransactionsOptions::TotalBalance: {

            system("cls");
            _ShowTotalBalanceScreen();
            _GoBackToMainMenue();
            break;
        }

        case enTransactionsOptions::Transfer: {

            system("cls");
            _ShowTransferScreen();
            _GoBackToMainMenue();
        }
                                       
        case enTransactionsOptions::TransferLog: {

            system("cls");
            _ShowTransferLog();
            _GoBackToMainMenue();
        }
        case enTransactionsOptions::Exit: {

            break;
        }
         
        }


    }

    


public:


    static void ShowTransactionsMenueScreen() {

        system("cls");
        _DrawScreenHeader("\t\tTransactions  Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposite.\n";
        cout << setw(37) << left << "" << "\t[2] WithDraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balacne.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer Money .\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log .\n";
        cout << setw(37) << left << "" << "\t[6] Exit .\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenue(enTransactionsOptions(_ReadTransactionsMenueOption()));

        

    }


};


