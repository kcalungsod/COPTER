#include "Header.h"

using namespace std;

void goodbye(string& name);
void tracker();
void predictor(string& name);
void fatalityrate();
void recoveryrate();
void error_check(int answer);
void error();

void help()
{
	cout << endl << "[COPTER]: I am a logical chatbot that allows you to get updated on the reported COVID-19 cases since the OMICRON variant has entered the Philippines." << endl;
	system ("pause");
	cout << "[COPTER]: I can also show you predictions regarding the growth rate of virus and the day the herd immunity can be achieved in this country." << endl;
	system ("pause");
	cout << "[COPTER]: If you want to view the past records of COVID-19 cases, please enter 1." << endl;
	system ("pause");
	cout << "[COPTER]: If you want to have an idea regarding the future in relation to the COVID-19 pandemic, please enter 2." << endl;
	system ("pause");
	cout << "[COPTER]: If you want to check the COVID-19 pandemic's fatality rate, please enter 3." << endl;
	system ("pause");
	cout << "[COPTER]: If you want to check the COVID-19 pandemic's recovery rate, please enter 4." << endl;
	system ("pause");
	cout << "[COPTER]: If you wish to end our conversation, you may enter 6." << endl;
	system ("pause");
	cout << "[COPTER]: In general, you just have to enter the corresponding number of your choice unless it is stated otherwise! I hope you have find me helpful!" << endl;	
}

void mainmenu(string &name)
{
	int answer;
	MENU:
		cout << "\n[COPTER]: How may I help you today? Please input the number corresponding to your choice!";
		cout << "\n(1) COVID-19 Tracker\n(2) COVID-19 Predictions\n(3) Fatality Rate\n(4) Recovery Rate\n(5) Help\n(6) Exit" << endl; 
		cout << "[" + name + "]: "; cin >> answer; 
	
	error_check(answer);		
	switch (answer)
	{
		case 1:
		    tracker();
		    system ("pause");
			goto MENU;
			break;
		case 2:
			predictor(name);
			system ("pause");
			goto MENU;
			break;
		case 3:
			fatalityrate();
			system ("pause");
			goto MENU;
			break;
		case 4:
			recoveryrate();
			system ("pause");
			goto MENU;
			break;
		case 5:
			help();
			system ("pause");
			goto MENU;
			break;
		case 6:
			goodbye(name);
			exit(0);
			break;
		default:
			error();
			system ("pause");
			goto MENU;
	}
}
