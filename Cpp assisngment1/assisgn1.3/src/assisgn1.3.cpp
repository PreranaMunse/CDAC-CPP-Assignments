//============================================================================
// Name        : 3.cpp
// Author      : prer
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {

	double temperature[3][3];

	//input temperature
	for(int i=0; i<3; i++){


		for (int j=0; j<3; j++)
		{

			cin >> temperature[i][j];
		}
	}


	double hottest = temperature[0][0];

		int hottestFloor;
		int hottestRoom;

	//display temperature

		cout << "          Room 1  Room 2  Room 3" << endl;

	for(int i = 0; i < 3; i++)
	{
		cout << "Floor  " << i+1 << " : ";

	    for(int j = 0; j < 3; j++)
	    {
	    	cout << temperature[i][j] << "  "  ;

	    }

	    cout << endl;
	}

	//hottest temperature

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(temperature[i][j] > hottest){

				hottest = temperature[i][j];
				hottestFloor = i;
				hottestRoom = j;
			}


		}


	}


	cout << endl;
	cout << "hottest temperature : " << hottest << endl;
	cout << endl;
	cout << "hottest floor : " << hottestFloor +1 << endl;
	cout << endl;
	cout << "hottest room : " << hottestRoom +1<< endl;
	cout << endl;



	return 0;
}
