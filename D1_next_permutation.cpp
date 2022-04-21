// @name: manojtomer0709
// @date: 21-4-2022
// problem link: https://leetcode.com/problems/next-permutation/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void getNextPermutation(vector<int>& arr){
    bool found = false;
    int j = arr.size() - 2;

    while (found == false && j >= 0){
        int key = arr[j];
        int nextgreater = key - 1;
        int nextgreaterindex = -1;
        
        for (int k = j+1; k < arr.size(); k++){
            if (arr[k] > key){
                if (nextgreater == key - 1){
                    nextgreater = arr[k];
                    nextgreaterindex = k;
                } 
                else if (arr[k] < nextgreater){
                    nextgreater = arr[k];
                    nextgreaterindex = k;
                } 
            }
        }

        if (nextgreater != key - 1){
            swap(arr[j], arr[nextgreaterindex]);
            sort(arr.begin()+j+1, arr.end());
            found = true;
            break;
        }

        j--;
    }

    if (found == false){
        sort(arr.begin(), arr.end());
    }
}

int main(){
    vector<int> arr = {5,4,3,2,1};

    getNextPermutation(arr);

    for (int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}