#include <iostream>
using namespace std;

int closestTriangular(int T) {
    int triangular_number = 0;
    int index = 1;

    while (triangular_number <= T) {
        triangular_number = (index * (index + 1)) / 2;
        index++;
    }

    return triangular_number - 1;
}

int main() {
    int T;
    cin >> T;
    
    int result = closestTriangular(T);
    cout << result << endl;
    
    return 0;
}
