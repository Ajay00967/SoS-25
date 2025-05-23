#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Given an non-empty array having a particular number once and all other element twice. Find that single number.
    // we have to thing of a way to cancel out the duplicates 
    // (like if there was + and - , we could have added all the number, same for reciprocal)

    // IMPORTANT thing of XOR :
    // XOR is associative :)
    // a ^ a = 0
    // a ^ 0 = a

    // so in this question we will take XOR of all the numbers and this will give the single number.
    // e.g. [a,a,b,b,c]
    // ans = a^a^b^b^c --> 0^0^c --> 0^c --> c

    vector<int> nums = {4,2,1,2,1};
    int ans = 0;
    for(auto val : nums) {
        ans ^= val;
    }
    cout << ans << endl;

    return 0;
}