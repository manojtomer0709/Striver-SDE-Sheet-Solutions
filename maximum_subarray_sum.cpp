#include<iostream>
#include<vector>
using namespace std;

void getMaximumSubarraySum(vector<int> arr){
    int maxSum = -2147483648;
    int startIndex = -1;
    int endIndex = -1;

    for (int i = 0; i < arr.size(); i++){
        for (int j = i; j < arr.size(); j++){
            int sum = 0;
            for (int k = i; k <= j; k++){
                sum += arr[k];
            }

            if (sum > maxSum){
                maxSum = sum;
                startIndex = i;
                endIndex = j;
            }
        }
    }

    for (int k = startIndex; k <= endIndex; k++){
        cout<<arr[k]<<" ";
    }
    cout<<endl;

    cout<<maxSum<<endl;
}

int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};

    getMaximumSubarraySum(arr);

    return 0;
}