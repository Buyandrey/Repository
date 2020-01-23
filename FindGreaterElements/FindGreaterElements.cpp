#include <iostream>
#include <vector>
#include <set>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    vector<T> res;
    
    auto v=find_if(begin(elements),end(elements),
        [&](T element){
            return element > border;
    });
    if (v != end(elements))
        for (auto it = v; it != end(elements); ++it)
            res.push_back(*it);
    return res;
}

int main() {
    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "python";
    cout << FindGreaterElements(set<string>{"c", "c++"}, to_find).size() << endl;
    return 0;

}
/* coursera
#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
  // ����� ������������� �� ���������
  auto it = begin(elements);
  // ���� � ����� ������ �������, ������� border
  // ���� �������� �� ������ ����� � ��������� �� ����, �������
  while (it != end(elements) && *it <= border) {
    ++it;
  }
  // ���������� ������, ��������� �� ��������� ���������, ������� � it
  return {it, end(elements)};
}
*/