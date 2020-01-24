#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
     ���� �������� �������� ������ 2 ���������, ����� �� �������.
     ������� ������, ���������� ��� �������� �������� ���������.
     ������� ������ �� ��� ������ �����. (� ���� ������ �������������,
    ��� ����� ������������� ��������� �������� �������� ������, ��� ��� ������ ������ ����� ������� �� ��� ������ �����.)
     ������� ������� MergeSort �� ������ �������� �������.
     � ������� ��������� merge ����� ��������������� ��������,
    ������� ���������� ��������������� �������� ������ ���������.
*/
template <typename RandomIt> void MergeSort(RandomIt range_begin, RandomIt range_end){
    if (range_begin + 1 == range_end)
        return;

    else {
        vector<typename RandomIt::value_type> elements(range_begin, range_end);

        MergeSort(begin(elements), begin(elements) + elements.size() / 2);
        sort(begin(elements), begin(elements) + elements.size() / 2);

        MergeSort(begin(elements) + elements.size() / 2, end(elements));
        sort(begin(elements) + elements.size() / 2, end(elements));

        merge(begin(elements), begin(elements) + elements.size() / 2,
              begin(elements) + elements.size() / 2, end(elements),
              range_begin);
        return;
    }
}
int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
/*\
Constructors called: 8          (8)
Copy constructors called: 24    (24)
Assignments made: 34            (24)
Comparisons made: 33            (13)
\*/