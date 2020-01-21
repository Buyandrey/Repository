#include "phone_number.h"

PhoneNumber::PhoneNumber(const string& in) {
	int n = in.size();

	int i = 0;
	for (const char& s : in) {
		if (i == 0) {
			if (s != '+')
				throw invalid_argument("IN[0]!='+'");
			else {
				i++;
				continue;
			}
		}
		else if (i == 4) {
			if (s != '-')
				throw invalid_argument("IN[4]!='-'");
			else {
				i++;
				continue;
			}
		}
		else if (i == 8) {
			if (s != '-')
				throw invalid_argument("IN[8]!='-'");
			else {
				i++;
				continue;
			}
		}
		else if (i < 4) {
			country_code_ += s;
			i++;
			continue;
		}
		else if (i > 4 && i < 8) {
			city_code_ += s;
			i++;
			continue;
		}
		else if (i > 8) {
			local_number_ += s;
			i++;
			continue;
		}
	}
	if(local_number_.size()==0 || city_code_.size() == 0 || country_code_.size() == 0)
		throw invalid_argument("Smth is empty");
}

string PhoneNumber::GetCountryCode() const {
	return country_code_;
}
string PhoneNumber::GetCityCode() const {
	return city_code_;
}
string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}
string PhoneNumber::GetInternationalNumber() const {
	return("+" + GetCountryCode() + "-" + GetCityCode() + "-" + GetLocalNumber());
}