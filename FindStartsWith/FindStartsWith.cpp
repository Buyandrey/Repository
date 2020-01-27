#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix) 
{
    
    auto start = find_if(range_begin, range_end, [&](string s) {
        return(s[0] == prefix);
    });
    if (start != range_end) {
        auto end = find_if(start, range_end, [&](string s) {
            return(s[0] != prefix);
        });
        pair<RandomIt, RandomIt> res = { start, end };
        return res;
    }
    
    else {
        auto end = find_if(range_begin, range_end, [&](string s) {
            //��, ���� ���������� ������ ��� ����������� ������
            return(s[0]>prefix);
        });
        start = end;
        pair<RandomIt, RandomIt> res = { start, end };
        return res;
    }
}
//abcdefghijkl m no p qrstu v wxyz
int main() {
    const vector<string> sorted_strings = { "moscow", "murmansk", "vologda" };

    const auto m_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto p_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
        (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
        (z_result.second - begin(sorted_strings)) << endl;

    return 0;
}