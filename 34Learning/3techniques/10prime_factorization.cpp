// find prime factorization of a given no n


//tc  o(root n)
#include <iostream>
using namespace std;

void primeFactorization(int n) {
    for (int i = 2; i * i <= n; ++i) {//i<=sqrt(n)
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    //n itself is prime
    if (n > 1) {
        cout << n;
    }

    cout << endl;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Prime factorization: ";
    primeFactorization(n);

    return 0;
}
