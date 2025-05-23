#include<iostream>
#include<regex>

#include<fstream>
#include<string>
#include"Hajj.h"
using namespace std;

void Registration::account()
{
	std::cout << "**Thank you soo much for visiting our website**" << endl;
	std::cout << "\nyou have to login or signup to fill the form" << endl;
	std::cout << "\nDo you have an account to login(y/n) : ";
	std::cin >> option;

	if (option == 'y' || option == 'Y')
	{
		login();
	}
	else
	{
		sign_up();
	}
}
void Registration::login()
{
	// Define a regular expression for the CNIC pattern
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	regex cnicPattern(R"(\d{5}-\d{7}-\d{1})");

	while (true) {
		std::cout << "Enter valid CNIC number in the format 12345-1234567-8: \n";
		getline(std::cin, CNIC);

		// Check if the entered CNIC matches the specified pattern
		if (regex_match(CNIC, cnicPattern)) {

			break;

		}
		else {
			std::cout << "Invalid CNIC format. Please enter a valid CNIC number in the format 12345-1234567-8." << endl;
		}

	}

	std::cout << "Enter password : ";

	getline(std::cin, password1);
	std::cout << "you account has been logged in now you can fill the form";
}
void Registration::sign_up()
{


	// creating new account to fill the form
	std::cout << "\ncreate a new account to login" << endl << endl;
	std::cout << "Enter Name : ";
	getline(std::cin, name);


	// Define a regular expression for the CNIC pattern

	regex cnicPattern(R"(\d{5}-\d{7}-\d{1})");

	while (true) {
		std::cout << "Enter valid CNIC number in the format 12345-1234567-8: \n";
		getline(std::cin, CNIC);

		// Check if the entered CNIC matches the specified pattern
		if (regex_match(CNIC, cnicPattern)) {
			break;

		}
		else {
			std::cout << "Invalid CNIC format. Please enter a valid CNIC number in the format 12345-1234567-8." << endl;
		}
		//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
	while (true) {
		std::cout << "Enter email in the format name@gmail.com.\n ";

		getline(std::cin, email);

		// Use regular expression to validate the email format


		if (regex_match(email, emailPattern)) {
			break;

		}
		else {
			std::cout << "Invalid email format. Please enter a valid email address in the format name@gmail.com." << endl;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}


	do {
		std::cout << "choose your password:";

		getline(std::cin, password1);
		std::cout << "re_enter your password";

		getline(std::cin, password2);
		if (password1 != password2)
		{

			std::cout << "\nyour passwords donot match plz re_enter your password" << endl;

		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	} while (password1 != password2);



	std::cout << "congratulations! your account has been created now you can fill the hajj form " << endl;
}




void Personal_info::form_fill()
{
	
	account();
	std::cout << "\n\nAPPLICANT'S INFORMATION :" << endl << endl;
	std::cout << "Enter your  name : ";
	getline(std::cin, name);
	std::cout << "Enter your gender (male or female) : ";
	getline(std::cin, gender);


	// Use regular expression to validate the email format
	regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
	while (true) {
		std::cout << "Enter email in the format name@gmail.com.:  ";

		getline(std::cin, email);


		//checking  email 
		if (regex_match(email, emailPattern)) {
			break;

		}
		else {
			std::cout << "Invalid email format. Please enter a valid email address in the format name@gmail.com." << endl;
		}
	}
	std::cout << "Enter your passport number (8 to 15 alphanumeric characters) : ";


	std::cin.ignore();
	regex passportPattern(R"([a-zA-Z0-9]{8,15})"); // Adjust the pattern as per your requirement
	while (true) {

		getline(std::cin, passport_No);


		// Check if the entered passport number matches the specified pattern
		if (regex_match(passport_No, passportPattern)) {

			break;
		}
		else {
			std::cout << "Invalid passport number. Please enter a valid passport number." << endl;


		}

	}
	std::cout << "Enter your address  : ";
	getline(std::cin, address);

	std::cout << "Enter your current city  : ";
	getline(std::cin, city);

	std::cout << "Number of days stay (38to42) or(20to25) : ";
	while (true) {


		std::cin >> daysInMakkah;
		if ((daysInMakkah >= 38 && daysInMakkah <= 42) || (daysInMakkah >= 20 && daysInMakkah <= 25))
		{
			break;
		}
		else
		{
			std::cout << "Invalid number of days stay. Please enter a value between 38 to 42 or 20 to 25." << endl;
		}
	}

	std::cout << "Enter your phone number : ";

	std::cin.ignore();

	// Adjust the pattern as per your requirement
	regex mobilepattern(R"([0-9]{11})");

	while (true)
	{
		getline(std::cin, Mobile_No);

		//check that ,mobile no matches the pattern
		if (regex_match(Mobile_No, mobilepattern))
		{
			break;
		}
		else
		{
			std::cout << "Invalid mobile number kindly enter a correct mobile number : " << endl;
		}

	}


	std::cout << "Enter age ";
	std::cin >> age;
}

void Personal_info::writetofile()
{

	ofstream outfile;
	outfile.open("hajj.doc", ios::app);

	if (outfile.is_open())
	{
		
		std::cout << "hajj file is created " << endl;

		// Write data to the file
		
		outfile << "Name:" << name << "\nGender: " << gender << "\nMobile number: " << Mobile_No
			<< "\nEmail: " << email << "\nCNIC number: " << CNIC << "\nPassport number: " << passport_No
			<< "\nAge: " << age << "\nAddress: " << address << "\nDays In Makkah: " << daysInMakkah << "\n";

		outfile.close();
	}
	else {
		std::cout << "File creation failed." << endl;
	}
}

void Flight::form_fill()
{
	Personal_info::form_fill();
	std::cin.ignore();
	cout << "\nFLIGHT DETAILS " << endl;
	cout << "Enter Airline: ";
	getline(std::cin, airline);


	regex patternFlightNum(R"([a-zA-Z0-9]{2,20})"); //Adjust the pattern as per your requirement

	while (true) {
		cout << "\nEnter Flight number: ";

		getline(std::cin, flight_num);
		if (regex_match(flight_num, patternFlightNum))// Check if the entered flight number matches the specified pattern
		{
			break;
		}
		else {
			std::cout << "Invalid flight number. Please enter a valid alphanumeric flight number (up to 20 characters): ";
		}

	}
	regex patternDepCity(R"([a-zA-Z]{4,20})");//Adjust the pattern as per your requirement

	while (true)
	{
		std::cout << "\nEnter Departure city: ";
		getline(std::cin, dep_city);
		if (regex_match(dep_city, patternDepCity))// Check if the entered departure city matches the specified pattern
		{
			break;
		}
		else {
			std::cout << "Invalid city name. Please enter a valid name: ";
		}


	}
	regex patternDesCity(R"([a-zA-Z]{4,20})"); // Adjust the pattern as per your requirement
	while (true)
	{
		cout << "\nEnter Destination city: ";
		getline(std::cin, des_city);

		if (regex_match(des_city, patternDesCity))// Check if the entered destination city matches the specified pattern
		{
			break;
		}
		else {
			std::cout << "\nInvalid city name. Please enter a valid name: ";
		}

	}
	std::regex patternDepTime(R"((1[0-2]|0?[1-9]):[0-5][0-9](am|pm))");//Adjust the pattern as per your requirement

	cin.ignore();
	while (true)
	{
		cout << "\nEnter Departure time(hrs:mints am/pm): ";
		getline(std::cin, dep_time);
		if (regex_match(dep_time, patternDepTime))// Check if the entered departure time matches the specified pattern
		{
			break;
		}
		else
		{
			std::cout << "Invalid time .please enter a valid time ";
		}
	}


	std::regex patternArrTime(R"((1[0-2]|0?[1-9]):[0-5][0-9](am|pm))"); // set pattern for arrival time



	while (true)
	{
		std::cout << "\nEnter Arrival time(am/pm): ";
		getline(std::cin, arr_time);

		if (regex_match(arr_time, patternArrTime))// Check if the entered arrival time matches the specified pattern
		{
			break;
		}
		else
		{
			std::cout << "Invalid time .please enter a valid time ";
		}
	}
	regex patternDepAirport(R"([a-zA-Z]{4,20})"); // set pattern for departure airport

	while (true)
	{
		cout << "\nEnter Departure Airport: ";
		getline(std::cin, dep_airport);
		if (regex_match(dep_airport, patternDepAirport))// Check if the entered departure airport matches the specified pattern
		{
			break;
		}
		else
		{
			cout << "invalid. enter valid airport name." << endl;
		}
	}
	regex patternArrAirport(R"([a-zA-Z]{4,20})"); // set pattern for arrival airport

	while (true)
	{
		cout << "\nEnter Arrival Airport: ";
		getline(std::cin, arr_airport);
		if (regex_match(arr_airport, patternArrAirport)) // Check if the entered arrival airport matches the specified pattern
		{
			break;
		}
		else
		{
			cout << "invalid. enter valid airport name." << endl;
		}
	}





	cout << "Select Flight Class (1 for Economy, 2 for Business): ";
	cin.ignore();
	while (true)
	{

		std::cin >> flightclass;

		if ((flightclass ==1)||(flightclass == 2))
		{
			break;
		}
		else {
			cout << "Invalid flight class. Please enter 1 for Economy or 2 for Business: ";

		}

	}
	
	cout << "\nEnter Departure Date(MMM DD,YYYY): ";
	getline(std::cin, dep_date);

	cout << "\nEnter Return Date(MMM DD,YYYY): ";
	getline(std::cin, ret_date);
}




void Flight::writetofile()
{
	Personal_info::writetofile();
	// Clear the input buffer
	std::cin.ignore();
	ofstream outfile;
	outfile.open("hajj.doc", ios::app);
	if (outfile.is_open()) {
		
		outfile << "\nAirline: " << airline << endl;
		outfile << "Flight number: " << flight_num << endl;
		outfile << "Departure city: " << dep_city << endl;
		outfile << "Destination city: " << des_city << endl;
		outfile << "Departure time: " << dep_time << " pst" << endl;
		outfile << "Arrival time: " << arr_time << " pst" << endl;
		outfile << "Departure airport: " << dep_airport << endl;
		outfile << "Arrival airport: " << arr_airport << endl;
		outfile << "Departure date: " << dep_date << endl;
		outfile << "Return date: " << ret_date << endl;
		switch (flightclass) {
		case 1:
			outfile << "Flight class: Economy class" << endl;
			break;
		case 2:
			outfile << "Flight class: Business class" << endl;
			break;
		default:
			outfile << "Unknown class" << endl;
		}
		outfile.close();
		std::cout << "Hajj file is created." << endl;
	}
	else
	{
		std::cout << "Error opening file" << endl;
	}
}


void EligibilityCriteria::fill_form()
{
	Flight::form_fill();
	cin.ignore();
	std::cout << "Enter your nationality (pakistani or non-pakistani): ";
	std::cin >> nationality;
	cin.ignore();
	std::regex patterncovid(R"(^(yes|no)$)");
	while (true) {
		std::cout << "Have you Received COVID-19 vaccination? (yes/no): ";
		getline(std::cin, covidVaccinated);
		if (regex_match(covidVaccinated, patterncovid))
		{
			break;
		}
		else {
			std::cout << "\nInvalid.please give me answer in (yes/no) : " << endl;
		}
	}
	cin.ignore();
	std::regex patternpolio(R"(^(yes|no)$)");

	while (true) {
		std::cout << "\nHave you Received polio vaccination? (yes/no): ";
		std::cin >> polioVaccinated;
		if (regex_match(polioVaccinated, patternpolio))
		{
			break;
		}
		else {
			std::cout << "\nInvalid.please give me answer in (yes/no) : " << endl;
		}
	}cin.ignore();
	std::regex patterndisable(R"(^(yes|no)$)");
	while (true) {
		std::cout << "Are you disabled ? (yes/no): ";
		getline(std::cin, isDisabled);
		if (regex_match(isDisabled, patterndisable))
		{
			break;
		}
		else
			cout << "\nInvalid .please give me answer in (yes/no) : " << endl;
	}

}



void EligibilityCriteria::checkEligibility() {
	cout << "Eligibility criteria " << endl;
	if ((nationality == "pakistani") && (covidVaccinated == "yes") && (polioVaccinated == "yes") && (isDisabled == "no"))
	{
		cout << "\nYou are Eligible " << endl;
	}
	else if ((nationality == "pakistani") && (covidVaccinated == "yes") && (polioVaccinated == "yes") && (isDisabled == "yes"))
	{
		cout << "\nyou are eligible but require a wheel chair " << endl;
	}
	else
	{
		cout << "\nyou are not eligible " << endl;
	}

}
void EligibilityCriteria::writetofile()
{
	Flight::writetofile();
	ofstream outfile;
	outfile.open("hajj.doc", ios::app);
	if (outfile.is_open()) {
		outfile << "\nNationality : " << nationality << "\nCovidVaccinated : " << covidVaccinated << "\nPolioVaccinated : " << polioVaccinated << "\nDisability : " << isDisabled << "\n";
		outfile.close();
		cout << "\nfile is created " << endl;
	}
	else
	{
		cout << "\nfile creation is failed " << endl;
	}

}

void QuotaReservation::reserveQuota()
{
	cout << "city" << city;
	std::cout << ".Quota Reservation\n";
	if((city=="karachi")||(city == "peshawar")|| (city == "gilgit")|| (city == "quetta" )||(city == "islamabad"))

	{
		std::cout << "Congratulations! Your seat has been reserved." << std::endl;
	}
	else {
		std::cout << "Sorry, all the quota seats have been reserved from your city. Please apply next time." << std::endl;
	}
}

// Constructor to initialize member variables

void Subtotal::cal_totalcost()
{



if((flightclass==1) && (Personal_info::daysInMakkah >= 20) && (Personal_info::daysInMakkah <= 25))
{
	cout << Personal_info::daysInMakkah;
	cout << endl << flightclass;
		flight_cost = 30000;
		total_cost = flight_cost + 60000;
	}
	else if((flightclass==2) && (Personal_info::daysInMakkah >= 20) && (Personal_info::daysInMakkah <= 25))
	{
		flight_cost = 50000;
		total_cost = flight_cost + 60000;
}
	else if ((flightclass == 1) && (Personal_info::daysInMakkah >= 38 && Personal_info::daysInMakkah <= 42))
{
	flight_cost = 30000;
		total_cost = flight_cost + 90000;

	}
	else if ((flightclass == 2)  &&(Personal_info::daysInMakkah >= 38 && Personal_info::daysInMakkah <= 42))
{
	flight_cost = 50000;
		total_cost = flight_cost + 90000;
}
std::cout << "\nYour flight cost is :" << flight_cost << endl;
}


void Confirmation::readfromfile()
{
	cout << "\n****Your Details****" << endl;
	ifstream infile;  // Use a different name for input file stream
	infile.open("hajj.doc");

	if (!infile.is_open()) {
		std::cout << "Error opening the file." << std::endl;
		return;
	}

	std::string line;
	// Read the file line by line
	while (std::getline(infile, line)) {
		// Process each line as needed
		std::cout << line << std::endl;
	}

	// Close the file
	infile.close();
}










void Confirmation::menu()
{
	cout << "-----------------------------------------" << endl;
	cout << "***Hajj Application System***" << endl;
	cout << "-----------------------------------------" << endl << endl;
	EligibilityCriteria::fill_form();
	EligibilityCriteria::writetofile();
	do {
		cout << "-----------------------------------------" << endl;
		cout << "***Hajj Application System***" << endl;
		cout << "-----------------------------------------" << endl << endl;
		cout << "  1. View your application form" << endl;
		cout << " 2.Check your eligibility criteria " << endl;
		cout << " 3.Check quota reservation " << endl;
		cout << " 4.Check Total amount " << endl;
		cout << " 5. Exit" << endl;
		cout << "-----------------------------------------" << endl;

		cout << "Enter your Choice ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		Confirmation readfromfile();
		break;
		case 2:
			checkEligibility();
			break;

		case 3:
			reserveQuota();
			break;
		case 4:
			
			cal_totalcost();
			break;
		case 5:
			cout << "\nExit program " << endl;
			exit(1);
			break;
		default:
			cout << "\nInvalid Choice " << endl;
		}
	} while (choice != 5);
	exit(1);
}
		
		
