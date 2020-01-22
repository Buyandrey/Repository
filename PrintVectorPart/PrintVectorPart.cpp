#include"PrintVectorPart.h"

void PrintVectorPart(const vector<int>& numbers) {

	//                 /b/  //  //  //  // e
	for (auto it = begin(numbers); it != end(numbers);it++) {
		if (*it < 0) {
			if (it == begin(numbers)) {
				break;
			}
			while (it != begin(numbers)) {
				--it;
				cout << *it << " ";
			}
			break;
		}
		if (it == end(numbers)-1) {
			while (1) {
				cout << *it << " ";
				--it;
				if (it == begin(numbers)) {
					cout << *it << " ";
					break;
				}
			}
			break;
		}
	}
}