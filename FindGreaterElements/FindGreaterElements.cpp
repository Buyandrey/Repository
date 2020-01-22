#include <iostream>
#include <vector>
#include <set>
/*
Напишите шаблонную функцию FindGreaterElements, принимающую множество elements
объектов типа T и ещё один объект border типа T и возвращающую вектор из всех 
элементов множества, бо́льших border, в возрастающем порядке.

>
7 8
0

*/
using namespace std;
template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
   
    vector<T> res;
        for (auto it = begin(elements); it != end(elements); it++) {
        auto result_it = 
            find_if(begin(elements), end(elements),
            [](/*очередной элемент*/const T& element) {
                return element > border;
            });
        if (result_it != end(elements)) {
            res.push_back(*result_it);
        }
    }

    
}

int main() {
    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
    return 0;
}