// @name: manojtomer0709
// @date: 21-4-2022
// problem link: https://leetcode.com/problems/pascals-triangle/

#include<iostream>
#include<vector>
using namespace std;

void generatePascalTriangle(int N){
    vector<vector<int>> PT;

    for (int i = 1; i <= N; i++){
        vector<int> level(i, 1);

        if (i == 1 || i == 2){
            PT.push_back(level);
            continue;
        }

        int j = 1;
        int k = 0;

        while (j < level.size()-1 && k < PT[PT.size()-1].size()-1){
            level[j] = PT[PT.size()-1][k] + PT[PT.size()-1][k+1];
            j++;
            k++;
        }

        PT.push_back(level);
    }

    for (int i = 0; i < PT.size(); i++){
        for (int j = 0; j < PT[i].size(); j++){
            cout<<PT[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int N = 8;

    generatePascalTriangle(N);

    return 0;
}