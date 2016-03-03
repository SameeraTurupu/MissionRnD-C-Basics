/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
bool isLeapYear(int year) {
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return true;
	return false;
}
bool validation(int day, int month, int year){
	bool valid = false;
	if (day <= 0 || month <= 0 || year <= 0)
		valid = false;
	else {
		if (month == 2) {
			bool leap = isLeapYear(year);
			if (leap == true) {
				if (day <= 29)
					valid = true;
			}

			else if (leap == false) {
				if (day <= 28)
					valid = true;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day <= 30)
				valid = true;
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day <= 31)
				valid = true;
		}
	}
	return valid;
}


int isOlder(char *dob1, char *dob2) {
	if (dob1[2] != '-' || dob1[5] != '-' || dob2[2] != '-' || dob2[5] != '-' ) {
		return -1;
	}
	int dayOfDob1 = (dob1[0] - '0') * 10 + (dob1[1] - '0');
	int monthOfDob1 = (dob1[3] - '0') * 10 + (dob1[4] - '0');
	int yearOfDob1 = (dob1[6] - '0') * 1000 + (dob1[7] - '0') * 100 + ((dob1[8] - '0') * 10 + dob1[9] - '0');
	int dayOfDob2 = (dob2[0] - '0') * 10 + (dob2[1] - '0');
	int monthOfDob2 = (dob2[3] - '0') * 10 + (dob2[4] - '0');
	int yearOfDob2 = (dob2[6] - '0') * 1000 + (dob2[7] - '0') * 100 + ((dob2[8] - '0') * 10 + dob2[9] - '0');
	if (!validation(dayOfDob1, monthOfDob1, yearOfDob1) || !validation(dayOfDob2, monthOfDob2, yearOfDob2))
		return -1;
	else {
		if (yearOfDob1 < yearOfDob2)
			return 1;
		else if (yearOfDob1 > yearOfDob2)
			return 2;
		else if (yearOfDob1 == yearOfDob2) {
			if (monthOfDob1 < monthOfDob2)
				return 1;
			else if (monthOfDob1 > monthOfDob2)
				return 2;
		    else if (dayOfDob1 < dayOfDob2)
			    return 1;
		    else if (dayOfDob1 > dayOfDob2)
			     return 2;
		    else
			    return 0;
		}
	}
}

