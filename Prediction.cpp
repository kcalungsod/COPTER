#include "Header.h"

using namespace std;

void mainmenu(string& name);
void goodbye(string& name);
void error_check(int answer);
void error(); 
string getDate();
int getTime();
int getEpoch();
int getCaseMil();
int getCounter();
void setCounter();

long totalCases, totalRecoveries, totalDeaths; 

void getTotal()
{
 	string stringDate, stringCases, stringRecoveries, stringDeaths, stringActives;
    long floatCases;
    long floatRecoveries;
    long floatDeaths;
    
    totalCases = 0;
	totalRecoveries = 0;
	totalDeaths = 0;

	ifstream getTotal;
	getTotal.open( "brain/database.txt" );	
    
    while(!getTotal.eof()){
    	getline(getTotal, stringDate, '|');
    	getline(getTotal, stringCases, '|');
    	getline(getTotal, stringRecoveries, '|');
    	getline(getTotal, stringDeaths, '|');
    	getline(getTotal, stringActives);
    	
    	stringstream ss1(stringCases);
		ss1 >> floatCases;
		totalCases += floatCases;
		
		stringstream ss2(stringRecoveries);
		ss2 >> floatRecoveries;
		totalRecoveries += floatRecoveries;
		
		stringstream ss3(stringDeaths);
		ss3 >> floatDeaths;
		totalDeaths += floatDeaths;
	}
	getTotal.close();
	
	cout << endl << "[COPTER]: Here are the Latest Amount of Confirmed Cases, Recoveries, and Deaths in the Philippines.";
	cout << endl << "Total Confirmed Cases: " << totalCases;
	cout << endl << "Total Recoveries: " << totalRecoveries;
	cout << endl << "Total Deaths: " << totalDeaths;
}

void fatalityrate()
{	
	getTotal();	
	double fatalityRate = (double)totalDeaths / (double)totalCases * 100;	
	cout << endl << "[COPTER]: The COVID-19 Fatality Rate is " << setprecision(3) << fatalityRate << " %" << endl << endl;
}

void recoveryrate()
{	
	getTotal();
	double recoveryRate = (double)totalRecoveries / (double)totalCases * 100;
	cout << endl << "[COPTER]: The COVID-19 Recovery Rate is " << setprecision(3) << recoveryRate << " %" << endl << endl;
}

void growthrate()
{	
	int timeDifference = getTime();
 	string stringDate, temp;
	int counter = 0;
	float startingvalue = 10233;
	float growthRate;
	float activeCases;
	float timeEpoch = getEpoch();
	float daySeconds = 86400;
	float nextDays;
	string nextDate[7];
	
	ifstream track;
	track.open( "brain/database.txt");	
  
	while(!track.eof()){
    	for(int i = 0; i < 5; i++){
    		if(i <= 3){
				getline(track, temp, '|');
			}
			else if (i == 4){
				getline(track, temp);
			}
    	}
	}
	track.close();

	stringstream ss(temp);
	ss >> activeCases;
	
	growthRate = ((log(activeCases / startingvalue)) / timeDifference) * 100;
	cout << endl << "[COPTER]: The COVID-19 Growth Rate is " << growthRate << "%" << endl;
	cout << "[COPTER]: Potential Number of Active Cases for the Next 7 Days" << endl;
	for(int i = 0; i < 7; i++){
		nextDays = timeEpoch + (daySeconds * (i + 1));
		time_t a = (time_t)nextDays;
	    struct tm *next = gmtime(&a);
	    int intDay = next->tm_mday + 1;
	    int intMonth = next->tm_mon + 1;
	    int intYear = next->tm_year + 1900;
	    
	    string stringDay, stringMonth, stringYear;
	    
	    stringstream ss1;
		ss1 << intDay;
		ss1 >> stringDay;
		
		stringstream ss2;
		ss2 << intMonth;
		ss2 >> stringMonth;
		
		stringstream ss3;
		ss3 << intYear;
		ss3 >> stringYear;
		
		int ACToday = startingvalue * exp((growthRate/100) * (timeDifference + (i + 1)));
		
		nextDate[i] = stringMonth + "." + stringDay + "." + stringYear;	
		cout << nextDate[i] << "\t|\tActive Cases: " <<  ACToday << endl;
	}
}

void herdimmune(string& name){
	string stringfullyVaccinated, stringdailyVaccine;
	int answer;
	int linkCounter = getCounter();
	cout << endl << "[COPTER]: Before we proceed on predicting the herd immunity in the Philippines, I will need your help in getting some of the information for me." << endl;
	system ("pause");
	cout << "[COPTER]: Let me brief you first on what will happen and what you're going to do." << endl;
	system ("pause");
	cout << "[COPTER]: The covidvax.live website will open on your default browser which will serve as your source of information." << endl;
	system ("pause");
	cout << "[COPTER]: Afterwards, you will see immediately all the necessary information about the provision of vaccines in the country which you will have to input in my brain." << endl;
	system ("pause");
	cout << "[COPTER]: That's all you have to do! Looking forward on your assistance! Thank you, " + name + "!" << endl;
	system ("pause");
	
	if (linkCounter == 0){
		ShellExecute(NULL, NULL, "https://covidvax.live/location/phl", NULL, NULL, SW_SHOWNORMAL);
		setCounter();
	}
		ANSWER:
		cout << endl << "[COPTER]: Kindly Input the Following Information";
		cout << endl << "Total Number of Completed Vaccination: ";
		cin >> stringfullyVaccinated;
		cout << "Number of Daily Doses: ";
		cin >> stringdailyVaccine;
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
				break;
			case 3:
				goodbye(name);
				exit(0);
				break;
			default:
				error();
				goto QUESTION;
		}
			
	int population = 111791127;
	float casepermil = getCaseMil();
	int intfullyVaccinated, intdailyVaccine;
	stringstream ss1(stringfullyVaccinated);
	ss1 >> intfullyVaccinated;
	stringstream ss2(stringdailyVaccine);
	ss2 >> intdailyVaccine;
	float r0 = (casepermil / 1000000) * 100;
	float sample = 1/r0;
	float herdThreshold = (1 - (1/r0)) * 100;
	long actualHerd = (herdThreshold / 100) * population;
	float currentHerdpercentage = ((float)intfullyVaccinated / (float)actualHerd) * 100;
	long missingPopulation = actualHerd - intfullyVaccinated; 
	int goalHerd = (missingPopulation / intdailyVaccine) * 2;
	
	float timeEpoch = getEpoch();
	float finalDay = (86400 * goalHerd) + timeEpoch;
	time_t a = (time_t)finalDay;
	struct tm *final = gmtime(&a);
	int intDay = final->tm_mday;
	int intMonth = final->tm_mon + 1;
	int intYear = final->tm_year + 1900;
	
	string stringDay, stringMonth, stringYear, herdDate;
	    
	stringstream ss3;
	ss3 << intDay;
	ss3 >> stringDay;
		
	stringstream ss4;
	ss4 << intMonth;
	ss4 >> stringMonth;
		
	stringstream ss5;
	ss5 << intYear;
	ss5 >> stringYear;		
	
	herdDate = stringMonth + "." + stringDay + "." + stringYear;	
		
	cout << "\n[COPTER]: Here are the details regarding COVID-19 Pandemic's Herd Immunity";
	cout << "\nReproduction Number: " << r0;
	cout << "\nTarget Percentage to achieve Herd Immunity: " << setprecision(4) << herdThreshold << "%";
	cout << "\nEquivalent Target Population to achieve Herd Immunity: " << actualHerd;
	cout << "\nPercentage of Herd Immunity Today: " << setprecision(4) << currentHerdpercentage << "%";
	cout << "\nAmount of People Needed to Get Vaccinated to Reach Herd Immunity: " << missingPopulation;
	cout << "\nPredicted Date of Herd Immunity: " << herdDate << endl;
}


void predictor(string& name)
{
	int answer;
	PREDICTION:
		cout << "\n[COPTER]: What would you like to predict regarding the COVID-19 Pandemic? Please input the number corresponding to your choice!";
		cout << "\n(1) Growth Rate\n(2) Herd Immunity\n(3) Back\n(4) Exit" << endl; 
		cout << "[" + name + "]: "; cin >> answer; 
	
	error_check(answer);		
	switch (answer)
	{
		case 1:
		    growthrate();
		    system ("pause");
			goto PREDICTION;
			break;
		case 2:
			herdimmune(name);
			system ("pause");
			goto PREDICTION;
			break;
		case 3:
			mainmenu(name);
			break;
		case 4:
			goodbye(name);
			exit(0);
			break;
		default:
			error();
			system ("pause");
			goto PREDICTION;
	}
}
