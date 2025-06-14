#include <iostream>
#include <vector>
using namespace std;

double pow(double x, int n) {
    // x^n --> convert n into binary (which will have log(n)+1 digits) 
    // and instead of making a loop which will make the time O(n) 
    // we will run a loop on the digits of the binary expansion of the number.
    // we can also add some of the corner cases like when x is 0,1,-1 or when n is 0,1 ;
    bool isNegative = (n < 0);
    // Instead of this we can also make x as 1/x for -ve power.
    double ans = 1;
    while(n) {
        if(n % 2) {
            ans *= x;
        }
        x *= x;
        n /= 2;
    }
    return (isNegative ? 1/ans : ans);
}

int main() {
    double x; 
    int n;
    cin >> x >> n;
    cout << x << "^(" << n << ") = " << pow(x,n) << endl;

    return 0;
}