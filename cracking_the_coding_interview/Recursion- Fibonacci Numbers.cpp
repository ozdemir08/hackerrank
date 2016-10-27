#include <iostream>

using namespace std;

int fibonacci(int n) {
    // Complete the function.
    if(!n || n == 1) return n;
    return fibonacci(n-2) + fibonacci(n-1);

}
int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
