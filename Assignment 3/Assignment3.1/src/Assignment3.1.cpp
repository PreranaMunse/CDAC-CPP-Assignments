//============================================================================
// Name        : 1.cpp
// Author      : prer
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

enum class HttpStatus {

OK             = 200,
Created        = 201,
BadRequest     = 400,
Unauthorized   = 401,
NotFound       = 404,
ServerError    = 500
};

void handleResponse(HttpStatus status, const string& endpoint)
{
	switch(static_cast<int>(status))
	{

	case 200 :
		cout << "OK :  " <<  "request successful" << endl;
		break;

	case 201 :
		cout << "Created :  " << "Request created" << endl;
		break;

	case 401 :
		cout << "Unauthorized :  " <<  "Authentication Required" << endl;
		break;

	case 404 :
		cout << "Not Found :  " <<  " Endpoint does not exist" << endl;
		break;

	case 500 :
		cout << "Service Error :  " <<  " Internal server error — retry later" << endl;
		break;

	}
}
int main() {

	cout << "GET /api/users   ->   ";
	handleResponse(HttpStatus::OK, "GET /api/users");

	cout << "POST /api/login   ->   ";
	handleResponse(HttpStatus::Unauthorized, "POST /api/login");

	cout << "GET /api/products/99   ->   ";
    handleResponse(HttpStatus::NotFound, "GET /api/products/99");

    cout <<"POST /api/order   ->   ";
    handleResponse(HttpStatus::ServerError, "POST /api/order");

	return 0;
}
