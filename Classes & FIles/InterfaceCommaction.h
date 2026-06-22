#pragma once
#include <iostream>
#include <string>

using namespace std;


class InterfaceCommaction {

public :

	virtual void SendEmail(string Tital, string Message) = 0;
	virtual void SendFax(string Tital, string Message) = 0;
	virtual void SendMessage(string Tital, string Message) = 0;
	
    
};

