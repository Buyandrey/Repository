#include "PrintVectorPart.h"

using namespace std;

int main() {
    PrintVectorPart({ 6, 1, 8, -5, 4 });
    cout << endl;
    PrintVectorPart({ -6, 1, 8, -5, 4 });  // ������ �� ���������
    cout << endl;
    PrintVectorPart({ 6, 1, 8, 5, 4 });
    cout << endl;
    PrintVectorPart({ 6, 1, 8, 5, -4 });
    cout << endl;
    return 0;
}