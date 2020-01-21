#include "phone_number.h"
#include <exception>
#include <stdexcept>

PhoneNumber::PhoneNumber(const string& in) {
	//+...-...-...................
	bool m = false;//��� �� �����
	bool l = false;//�������� �� �������
	int k = 0;	   //0-cou//1-cit//2-local
	int i = 0;
	for (const char& s : in) {
		//������� �� ������ ������
		if (i == 0 && s == '+') {
			i++;
			continue;
		}
		else if (i == 0 && s != '+') {
			throw invalid_argument("No '+'");
		}
		
		//���������� ����� ������ � ��� ������
		if (m == false && s == '-'&& l==false) {
			k++;
			i++;
			m = true;
			continue;
		}
		//���������� ����� ������ � ������
		if (m == true && s == '-' && l==false) {
			k++;
			i++;
			l = true;
			continue;
		}
		//������ � ������ �����
		if (k == 0) {
			country_code_ += s;
		}else
			if (k == 1) {
				city_code_ += s;
			}else 
				if (k == 2) {
					local_number_ += s;
			}
		i++;
	}
	//��������� ����� ������ �� ���������
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