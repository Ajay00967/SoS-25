#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> v) {
    // 7,1,5,3,6,4
    // imagine every day as a selling day
    // and check for the min price in the past
    int maxP = 0;
    int bestBuy = v.front();
    for(int i=1; i<v.size(); i++) {
        maxP = max(maxP, v[i]-bestBuy);
        bestBuy = min(bestBuy, v[i]);
    }
    return maxP;
}

int main() {
    // here number corresponding to ith index will depict the stock price on that day
    // we need to find the max profit, such that we buy and sell stocks on different day(obviously in future after we bought the stock);
    vector<int> v = {7,1,5,3,6,4};
    cout << maxProfit(v) << endl;

    return 0;
}