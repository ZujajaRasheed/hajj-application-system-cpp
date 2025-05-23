#pragma once
#include<string>
class Registration
{
protected:
	std::string name;
	std::string CNIC;
	std::string email;
	std::string password1;
	std::string password2;

	char option;


public:

	void login();
	void sign_up();
	void account();


};
class Personal_info:public Registration
{

protected:

	std::string passport_No;
	std::string gender;
	std::string city;
	std::string address;
	std::string Mobile_No;
	int daysInMakkah;
	int age;
public:
	
	void form_fill();
	void writetofile();

};


class Flight :public Personal_info
{
protected:
	std::string airline;
	std::string flight_num;
	std::string dep_city;
	std::string des_city;
	std::string dep_time;
	std::string arr_time;
	std::string dep_airport;
	std::string arr_airport;
	std::string dep_date;
	std::string ret_date;
	std::string nationality;
	int flightclass;
public:

	void form_fill();
	void writetofile();
};
class EligibilityCriteria :public Flight
{
private:
	std::string nationality;
	std::string covidVaccinated;
	std::string polioVaccinated;
	std::string isDisabled;

public:
	void fill_form();
	void checkEligibility();
	void writetofile();
};


class QuotaReservation :public Personal_info {
public:
	void reserveQuota();
};

class Subtotal : public Flight,public Personal_info
{
private:
	int flight_cost;
	int total_cost;
public:
	
	void cal_totalcost();
};
class Confirmation :public Personal_info, public Flight, public EligibilityCriteria, public QuotaReservation, public Subtotal
{
	int choice;
public:
	void menu();
	void readfromfile();
};