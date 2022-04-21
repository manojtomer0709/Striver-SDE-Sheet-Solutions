// @name: manojtomer0709
// @date: 21-4-2022
// problem link: https://leetcode.com/problems/set-matrix-zeroes/

#include<iostream>
#include<vector>
using namespace std;

void my_solution(vector<vector<int>>& V){
    vector<pair<int, int>> zeroLoc;

    for (int i = 0; i < V.size(); i++){
        for (int j = 0; j < V[i].size(); j++){
            if (V[i][j] == 0){
                zeroLoc.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < zeroLoc.size(); i++){
        int row = zeroLoc[i].first;
        int column = zeroLoc[i].second;
        for (int a = 0; a < V[0].size(); a++){
            V[row][a] = 0;
        }
        for (int b = 0; b < V.size(); b++){
            V[b][column] = 0;
        }
    }
}

void brute_force_solution(vector<vector<int>>& V){
    for (int i = 0; i < V.size(); i++){
        for (int j = 0; j < V[i].size(); j++){
            if (V[i][j] == 0){
                for (int a = 0; a < V[0].size(); a++){
                    if (V[i][a] == 0) continue;
                    V[i][a] = -1;
                }
                for (int b = 0; b < V.size(); b++){
                    if (V[b][j] == 0) continue;
                    V[b][j] = -1;
                }
            }
        }
    }

    for (int i = 0; i < V.size(); i++){
        for (int j = 0; j < V[i].size(); j++){
            if (V[i][j] == -1){
                V[i][j] = 0;
            }
        }
    }
}

void better_solution(vector<vector<int>>&V){
    vector<int> A(V.size(), 0);
    vector<int> B(V[0].size(), 0);

    for (int i = 0; i < V.size(); i++){
        for (int j = 0; j < V[i].size(); j++){
            if (V[i][j] == 0){
                A[i] = 1;
                B[j] = 1;
            }
        }
    }

    for (int i = 0; i < V.size(); i++){
        for (int j = 0; j < V[i].size(); j++){
            if (A[i] || B[j]) V[i][j] = 0;
        }
    }
}

int main(){
    vector<vector<int>> V = {{1,2,3}, {1,3,5}, {0, 1,0}};

    // my_solution(V);

    // brute_force_solution(V);

    better_solution(V);

    for (int i = 0; i < V.size(); i++){
        for (int j = 0; j < V[i].size(); j++){
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}