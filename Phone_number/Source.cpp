#include <iostream>
#include <exception>

#include "phone_number.h"

using namespace std;

int main() {
    /* ��������� ������ � ������� +XXX-YYY-ZZZZZZ
   ����� �� '+' �� ������� '-' - ��� ��� ������.
   ����� ����� ������ � ������ ��������� '-' - ��� ������
   ��, ��� ��� ����� ������� ������� '-' - ������� �����.
   ��� ������, ��� ������ � ������� ����� �� ������ ���� �������.
   ���� ������ �� ������������� ����� �������, ����� ��������� ���������� invalid_argument. ���������, ��� ����� �������� ������ �����, �� �����.

   �������:
   * +7-916-1917225
   * +7-495-111-22-33
   * +7-495-1112233
   * +323-22-460002
   * +1-2-coursera-cpp
   * 1-2-333 - ������������ ����� - �� ���������� �� '+'
   * +7-1233 - ������������ ����� - ���� ������ ��� ������ � ������
    */
    try {
        PhoneNumber pn("+a-s-333-222-dffdx");
        cout << pn.GetCountryCode() << '/' << pn.GetCityCode() << '/' << pn.GetLocalNumber() << endl;
        cout << pn.GetInternationalNumber();
    }
    catch (exception & e) {
        cout << " Error " << e.what() << endl;
    }
	return 0;
}