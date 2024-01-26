#include "class.h"

using namespace std;

Alumni::Alumni() {
	lastName = "";
	firstName = "";
	comp = "";
	address = "";
	city = "";
	state = "";
	zip = "";
	phoneNumber = "";
	email = "";
}

Alumni::Alumni(string lName, string fName, string company, string streetAddress, string cityName,
	string stateName, string zipcode, string phone, string emailAddress) {
	setLastName(lName);
	setFirstName(fName);
	setCompanyName(company);
	setAddress(streetAddress);
	setCity(cityName);
	setState(stateName);
	setZip(zipcode);
	setPhoneNumber(phone);
	setEmail(emailAddress);
}
vector<string> Alumni::toVect() {
	vector<string> v{ lastName,firstName,comp ,address ,city,state ,zip,phoneNumber,email };
	return v;
}

void Alumni::setLastName(string lName) {
	lastName = lName;
}
void Alumni::setFirstName(string fName) {
	firstName = fName;
}
void Alumni::setCompanyName(string company) {
	comp = company;
}
void Alumni::setAddress(string streetAddress) {
	address = streetAddress;
}
void Alumni::setCity(string cityName) {
	city = cityName;
}
void Alumni::setState(string stateName) {
	state = stateName;
}
void Alumni::setZip(string zipcode) {
	zip = zipcode;
}
void Alumni::setPhoneNumber(string phone) {
	phoneNumber = phone;
}
void Alumni::setEmail(string emailAddress) {
	email = emailAddress;
}

string Alumni::getLastName() {
	return lastName;
}
string Alumni::getFirstName() {
	return firstName;
}
string Alumni::getCompanyName() {
	return comp;
}
string Alumni::getAddress() {
	return address;
}
string Alumni::getCity() {
	return city;
}
string Alumni::getState() {
	return state;
}
string Alumni::getZip() {
	return zip;
}
string Alumni::getPhoneNumber() {
	return phoneNumber;
}
string Alumni::getEmail() {
	return email;
}