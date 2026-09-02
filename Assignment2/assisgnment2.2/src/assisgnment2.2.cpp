//============================================================================
// Name        : 2.cpp
// Author      : prer
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class Patient{

private:

	int patientId;
	string name;
	int age;
	string ward;
	const string bloodGroup;

public:

	// Constructor 1
	Patient()

	  : patientId(0), name("Unknown"), age(0), ward("General"), bloodGroup("O+")
	{
	 cout << "[Constructor] Default Patient register" << endl;

	}

	// Constructor 2
	Patient(int id, const string& nm)
		 : patientId(id), name(nm), age(0), ward("General"), bloodGroup("Unknown")
		    {
		        cout << "[Constructor] Emergency: " << name << endl;
		    }


	//Constructor 3
	Patient(int id, const string& nm, int ag, const string& wd, const string& bg)

		: patientId(id), name(nm), age(ag), ward(wd), bloodGroup(bg)
		    {
		        cout << "[Constructor] Full admission: " << name << endl;
		    }


	//Destructor

	~Patient()
	{
		 cout << "[Destructor] Patient " << name << " discharged." << endl;
	}

	void displayRecord() const {
	        cout << "\nPatient Record:\n";
	        cout << "ID        : " << patientId << endl;
	        cout << "Name      : " << name << endl;
	        cout << "Age       : " << age << endl;
	        cout << "Ward      : " << ward << endl;
	        cout << "Blood Grp : " << bloodGroup << endl;
	    }

	    void transferWard(const string& newWard) {
	        cout << "\nWard Transfer: " << name << " -> " << newWard << endl;
	        ward = newWard;
	    }
	    void setDetails(int id, const string& nm, int ag, const string& wd) {

	    	patientId = id;
	        name = nm;
	        age = ag;
	        ward = wd;
	    }
};

int main() {

	// 1
	    Patient p1(1001, "Meera Joshi", 34, "Cardiology", "B+");
	    Patient p2(1002, "Raj Patel");
	    Patient p3;


	//2

	    Patient* wardBlock = new Patient[4];
	    wardBlock[0].setDetails(1003,"Anil Kumar", 45, "Orthopedics");
	    wardBlock[1].setDetails(1004, "Sunita Rao", 29, "Maternity");
	    wardBlock[2].setDetails(1005,"Raj Patil", 60, "ICU");
	    wardBlock[3].setDetails(1006,"Priya Singh", 12, "Pediatrics");


    //3
	    for (int i = 0; i < 4; i++) {
	            wardBlock[i].displayRecord();
	        }


	        p1.displayRecord();
	        p2.displayRecord();
	        p3.displayRecord();

	//4
	        p2.transferWard("ICU");
	        p2.displayRecord();



	// 5. delete[]

	        delete[] wardBlock;

	return 0;
}
