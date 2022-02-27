#include "Header.h"

using namespace std;

void mainmenu(string& name);
void error_check(int answer);
void error();

int counter = 0;
int timeDifference;
string today;
int epoch;
int linkCounter = 0;

int getTime()
{
	return timeDifference;
}

string getDate()
{
	return today;
}

int getEpoch()
{
	return epoch;
}

int getCaseMil()
{
	string stringDate, stringcasesMillion;
	int intcasesMillion;
	
	ifstream herd;
	herd.open( "brain/casespermillion.txt" );	
    
    
    while(!herd.eof()){
    	getline(herd, stringDate, '|');
    	getline(herd, stringcasesMillion);
	}			
	herd.close();
	stringstream ss(stringcasesMillion);
	ss >> intcasesMillion;
	return intcasesMillion;
}

int getCounter()
{
	return linkCounter;
}

void setCounter(){
	linkCounter = 1;
}

void goodbye(string& name){

	cout << "\n[COPTER]: Goodbye," + name + "! I hope that was informative! \n"; 
	cout << "\t\t\t        _____________________\n";
	cout << "\t\t\t       | ___________________ |\n";
	cout << "\t\t\t       ||   _           _   ||\n";
	cout << "\t\t\t       ||  | |         | |  ||\n"; 
	cout << "\t\t\t       ||      _______      ||\n";  
	cout << "\t\t\t       ||     |_|_|_|_|     ||\n";
	cout << "\t\t\t       ||___________________||\n";
	cout << "\t\t\t       |_____________________|\n";
	cout << "\t\t\t              _|     |_\n";
	cout << "\t\t\t             |_________|\n";
	cout << "____________________________________________________________________________________\n";
	
	system("pause");
	exit(0);
}

tm make_tm(int year, int month, int day)
{
    std::tm tm = {0};
    tm.tm_year = year - 1900; // years count from 1900
    tm.tm_mon = month - 1;    // months count from January=0
    tm.tm_mday = day;         // days count from 1
    return tm;
}

void updateDatabase(string date, string cases, string recoveries, string deaths, string actives, string casesmillion)
{
	ofstream update1;
	// std::ios::app is the open mode "append" meaning
	// new data will be written to the end of the file.
	update1.open("brain/database.txt", ios::app);

	update1 << endl << date << "|" << cases << "|" << recoveries << "|" << deaths << "|" << actives;
	update1.close();
	
	ofstream update2;
	update1.open("brain/casespermillion.txt", ios::app);

	update1 << endl << date << "|" << casesmillion;
	update1.close();
}

void updateChecker(string date, int time, string& name)
{	
 	string stringDate, stringCases, stringRecoveries, stringDeaths, stringActives;
	string dailyCases, dailyRecoveries, dailyDeaths, dailyActives, casesMillion;
	int answer;
	int cm;
	
	ifstream updateChecker;
	updateChecker.open( "brain/database.txt" );	
    
    while(!updateChecker.eof()){
    	getline(updateChecker, stringDate, '|');
    	getline(updateChecker, stringCases, '|');
    	getline(updateChecker, stringRecoveries, '|');
    	getline(updateChecker, stringDeaths, '|');
    	getline(updateChecker, stringActives);
		
		if(date == stringDate) {
			counter++;
		}
	}
	updateChecker.close();
	
	if (counter == 0 && time >= 57600)
	{
		cout << endl << "[COPTER]: Oops! It seems like I don't have any record on the COVID-19 cases in the Philippines today." << endl;
		system ("pause");
		cout << "[COPTER]: That being said, I will need your help in getting those data before proceeding but let me give you some quick instructions first." << endl;
		system ("pause");
		cout << "[COPTER]: The worldometer website will open on your default browser which will serve as your source of information." << endl;
		system ("pause");
		cout << "[COPTER]: You will have to scroll down until you see a table containing the countries together with the live statistics about the COVID-19 Coronavirus Pandemic." << endl;
		system ("pause");
		cout << "[COPTER]: Click on the search bar and type 'Philippines'. Afterwards, it will show you all the information you will need to input in my brain. " << endl;
		system ("pause");
		cout << "[COPTER]: That's all you have to do! Looking forward on your help! Thank you, " + name + "!" << endl;
		system ("pause");
		
		ShellExecute(NULL, NULL, "https://www.worldometers.info/coronavirus/", NULL, NULL, SW_SHOWNORMAL);
		ANSWER:
		cout << endl << "[COPTER]: Kindly Input the Following Information";
		cout << endl << "Daily Number of Confirmed Cases: ";
		cin >> dailyCases;
		cout << "Daily Number of Recoveries: ";
		cin >> dailyRecoveries;
		cout << "Daily Number of Deaths: ";
		cin >> dailyDeaths;
		cout << "Total Number of Active Cases Today: ";
		cin >> dailyActives;	
		cout << "Total Cases per 1M Population: ";
		cin >> casesMillion;
		
		QUESTION:
		cout << endl << "[COPTER]: Are there any mistakes from your entered data above?";
		cout << "\n(1) Yes\n(2) No\n(3) Exit" << endl;
		cout << "[" + name + "]: "; cin >> answer; 
	
		error_check(answer);		
		switch (answer)
		{
			case 1:
				goto ANSWER;
				break;
			case 2:
				updateDatabase(date, dailyCases, dailyRecoveries, dailyDeaths, dailyActives, casesMillion);
				break;
			case 3:
				goodbye(name);
				exit(0);
				break;
			default:
				error();
				goto QUESTION;
		}
	}
}

int main (){	
	system ("title COPTER");
	
	string username;
	
	cout << "\t\t\t\t     !!WELCOME!!\n";
	cout << "\t\t\t        _____________________\n";
	cout << "\t\t\t       | ___________________ |\n";
	cout << "\t\t\t       ||                   ||\n";
	cout << "\t\t\t       ||  [.]         [.]  ||\n";
	cout << "\t\t\t       ||                   ||\n";
	cout << "\t\t\t       ||     |_______|     ||\n";
	cout << "\t\t\t       ||___________________||\n";
	cout << "\t\t\t       |_____________________|\n";
	cout << "\t\t\t              _|     |_\n";
	cout << "\t\t\t             |_________|\n";
	cout << "____________________________________________________________________________________\n\n";
	cout << "[COPTER]: Hello, I am COPTER - your COVID-19 Tracker and Predictor Bot. What's your name?\n"; 
	cout << "[User]: "; cin >> username;
		
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);
	
	int intDay = aTime->tm_mday;
	int intMonth = aTime->tm_mon + 1;
	int intYear = aTime->tm_year + 1900;
	
	string stringDay, stringMonth, stringYear, currentDate; 
	
	stringstream ss1;
	ss1 << intDay;
	ss1 >> stringDay;
	
	stringstream ss2;
	ss2 << intMonth;
	ss2 >> stringMonth;
	
	stringstream ss3;
	ss3 << intYear;
	ss3 >> stringYear;
	
	currentDate = stringMonth + "." + stringDay + "." + stringYear;	
	today = currentDate;
	
	tm tm1 = make_tm(intYear,intMonth,intDay); //time using epoch where it calculates the number of seconds since the 1900 up to date.
	tm tm2 = make_tm(2021,12,14);
	
	time_t time1 = std::mktime(&tm1);
	epoch = time1;
	time_t time2 = std::mktime(&tm2);
	
	time_t seconds;
	time(&seconds);
	int currentTime = seconds - time1;

	const int seconds_per_day = 60*60*24;
	time_t difference = (time1 - time2) / seconds_per_day;
	timeDifference = difference;
	
	updateChecker(currentDate, currentTime, username);
	
	mainmenu(username);
	return(0);
}
