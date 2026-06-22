#include <iostream>
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsLoginScreen.h"

using namespace std;







int main() {


	while (true) {

		if (!clsLoginScreen::Login()) {

			break;
		}
	}


	system("pause > 0 ");

}

