#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
     Если диапазон содержит меньше 2 элементов, выйти из функции.
     Создать вектор, содержащий все элементы текущего диапазона.
     Разбить вектор на две равные части. (В этой задаче гарантируется,
    что длина передаваемого диапазона является степенью двойки, так что вектор всегда можно разбить на две равные части.)
     Вызвать функцию MergeSort от каждой половины вектора.
     С помощью алгоритма merge слить отсортированные половины,
    записав полученный отсортированный диапазон вместо исходного.
*/
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    int range_length = range_end - range_begin;
    if (range_length < 2) {
        return;
    }

    vector<typename RandomIt::value_type> elements(range_begin, range_end);

    auto mid = elements.begin() + range_length / 2;

    MergeSort(elements.begin(), mid);
    MergeSort(mid, elements.end());

    merge(elements.begin(), mid, mid, elements.end(), range_begin);
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