#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

bool print_permutation(const int& n,string& s) {
    //try {
        if (n <= 0 || n >= 10)
            //throw exception("Wrong format!!!");
            return 1;
        else {
            for (int i = n; i > 0; i--)
                s += char(i + 48);
            sort(s.begin(), s.end(), greater<char>());
            do {

                for (const char& i : s) {
                    cout << i << ' ';
                }cout << endl;
            } while (prev_permutation(s.begin(), s.end()));
        }
        return 0;
    //}
    //catch (exception & e) {
    //    cerr << e.what();

    //}
}

int main()
{
    int n;
    string s;
    cin >> n;
bool r=print_permutation(n, s);
return r;
}
/*coursera
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  int range_length;
  cin >> range_length;
  vector<int> permutation(range_length);

  // iota             -> http://ru.cppreference.com/w/cpp/algorithm/iota
  // ��������� �������� ��������������� ������������� ����������
  iota(permutation.begin(), permutation.end(), 1);

  // reverse          -> http://ru.cppreference.com/w/cpp/algorithm/reverse
  // ������ ������� ���������� ��������� � ��������� �� ���������������
  reverse(permutation.begin(), permutation.end());

  // prev_permutation ->
  //     http://ru.cppreference.com/w/cpp/algorithm/prev_permutation
  // ����������� �������� � ���������� (�����������������) ������������,
  // ���� ��� ����������, � ���������� true,
  // ����� (���� �� ����������) - � ��������� (����������) � ���������� false
  do {
    for (int num : permutation) {
      cout << num << ' ';
    }
    cout << endl;
  } while (prev_permutation(permutation.begin(), permutation.end()));

  return 0;
}
*/