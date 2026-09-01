//============================================================================
// Name        : 1.cpp
// Author      : prer
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	double temperature;
	double fahrenheit;
	int statuscode;

	cout <<"Enter the Temperature" << endl;
	cin >> temperature;

		//Statuscode if else

	if(temperature<0){
		 statuscode = -1;
	}
	else if(temperature<=29){
		statuscode = 0;
	}
	else if(temperature<=44){
		statuscode = 1;
	}
	else if (temperature<=59){
		statuscode = 2;
	}
	else {
		statuscode = 3;
	}

	//Fahrenheit

	fahrenheit = (temperature*9 / 5) + 32;
	 cout << "Temperature : " <<temperature << "°C/" <<fahrenheit << "°F"  <<endl;

	 cout << "Status :     ";

	//switch for action

	switch(statuscode){
	case -1:
		cout << "SENSOR_ERROR "<< endl;
		cout << "Action : Sensor fault — checkwiring" << endl;
		break;

	case 0:
		cout <<"NORMAL"<< endl;
		cout << "Action :No action required" << endl;
		break;

	case 1:
		cout<< "WARNING"<< endl;
		cout << "Action :Alert sent to supervisor" << endl;
		break;

	case 2:
		cout <<"CRITICAL"<<endl;
		cout <<"Action :Cooling system triggered" << endl;
		break;

	case 3:
		cout<<"SHUTDOWN"<<endl;
		cout <<"Action :Emergency shutdown initiated" << endl;
		break;
	}

	//ternary operator
	cout<< "Reading :     "
			<<(temperature<=25 ? "Above average" : "Below average")<<endl;

	return 0;
}

