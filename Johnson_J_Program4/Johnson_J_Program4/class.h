#ifndef ALUMNI_H
#define ALUMNI_H

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<vector>
#include <iterator>

using namespace std;


class Alumni {

private:
	string lastName;
	string firstName;
	string comp;
	string address;
	string city;
	string state;
	string zip;
	string phoneNumber;
	string email;


public:
	Alumni(); //Default constructor
	Alumni(string lName, string fName, string company, string streetAddress, string cityName,
		string stateName, string zipcode, string phone, string emailAddress);

	//Get and set functions for member variables
	void setLastName(string lName);
	void setFirstName(string fName);
	void setCompanyName(string company);
	void setAddress(string streetAddress);
	void setCity(string cityName);
	void setState(string stateName);
	void setZip(string zipcode);
	void setPhoneNumber(string phone);
	void setEmail(string emailAddress);
	string getLastName();
	string getFirstName();
	string getCompanyName();
	string getAddress();
	string getCity();
	string getState();
	string getZip();
	string getPhoneNumber();
	string getEmail();

	vector<string>toVect();
};





#endif
