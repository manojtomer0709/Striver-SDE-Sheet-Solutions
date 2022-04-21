// @name: manojtomer0709
// @date: 21-4-2022
// problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<iostream>
#include<vector>
using namespace std;

// Time Limit Exceeds. Quadratic Time
void getBestProfit(vector<int> arr){
    int maxProfit = -2147483648; // INT_MIN

    for (int i = 0; i < arr.size()-1; i++){
        for (int j = i+1; j < arr.size(); j++){
            int profit = arr[j] - arr[i];

            maxProfit = max(maxProfit, profit);
        }
    }

    if (maxProfit <= 0) cout<<0<<endl;
    else cout<<maxProfit<<endl;
}

// Optimal Solution. Linear Time
void getBestProfit_(vector<int> arr){
    int minimumBuy = arr[0];
    int maxProfit = 0;

    for (int i = 0; i < arr.size(); i++){
        minimumBuy = min(arr[i], minimumBuy);
        maxProfit = max(maxProfit, arr[i] - minimumBuy);
    }

    cout<<maxProfit<<endl;
}

int main(){
    vector<int> arr = {7,1,5,3,6,4};

    getBestProfit(arr);

    return 0;
}