// @name: manojtomer0709
// @date: 21-4-2022
// problem link: https://leetcode.com/problems/sort-colors/

#include<iostream>
#include<vector>
using namespace std;

void sorting(vector<int>& arr){
    int frequencies[] = {0,0,0};

    for (int i = 0; i < arr.size(); i++){
        if (arr[i] == 0) frequencies[0]++;
        if (arr[i] == 1) frequencies[1]++;
        if (arr[i] == 2) frequencies[2]++;
    }

    int a = frequencies[0] - 1;
    int b = frequencies[0] + frequencies[1] - 1;
    
    for (int i = 0; i < arr.size(); i++){
        if (i <= a) arr[i] = 0;
        else if (i > a && i <= b) arr[i] = 1;
        else arr[i] = 2;
    }
}

int main(){
    vector<int> arr = {0,1,1,1,2,0,0,2,1,2,2,0};

    sorting(arr);

    for (int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}