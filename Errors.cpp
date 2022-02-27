#include "Header.h"

using namespace std;

void error_check(int answer){
	if (isdigit(answer)==false){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void error()
{
	cout << "\n[COPTER]: Unfortunately, COPTER can't understand your input :( Please retry and enter the corresponding number of your choice. Thank you!" << endl;
}
