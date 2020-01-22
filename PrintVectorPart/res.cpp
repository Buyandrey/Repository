#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
    auto negative_it = find_if(
        numbers.begin(), numbers.end(),
        [](int number) {
            return number < 0;
        }
    );

    for (auto it = negative_it; it != numbers.begin(); ) {
        cout << *(--it) << " ";
    }
}
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//void PrintVectorPart(const vector<int>& numbers) {
//
//	//                 /b/  //  //  //  // e
//	for (auto it = begin(numbers); it != end(numbers); it++) {
//		if (*it < 0) {
//			if (it == begin(numbers)) {
//				break;
//			}
//			while (it != begin(numbers)) {
//				--it;
//				cout << *it << " ";
//			}
//			break;
//		}
//		if (it == end(numbers) - 1) {
//			while (1) {
//				cout << *it << " ";
//				--it;
//				if (it == begin(numbers)) {
//					cout << *it << " ";
//					break;
//				}
//			}
//			break;
//		}
//	}
//}
//int main() {
//    PrintVectorPart({ 6, 1, 8, -5, 4 });
//    cout << endl;
//    PrintVectorPart({ -6, 1, 8, -5, 4 });  // ничего не выведется
//    cout << endl;
//    PrintVectorPart({ 6, 1, 8, 5, 4 });
//    cout << endl;
//    PrintVectorPart({ 6, 1, 8, 5, -4 });
//    cout << endl;
//    return 0;
//}
///* coursera
//#include <algorithm>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void PrintVectorPart(const vector<int>& numbers) {
//  auto negative_it = find_if(
//	numbers.begin(), numbers.end(),
//	[](int number) {
//	  return number < 0;
//	}
//  );
//
//  for (auto it = negative_it; it != numbers.begin(); ) {
//	cout << *(--it) << " ";
//  }
//}
//*/