#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& sudoku,int val,int row,int col){
    for(int i = 0;i<sudoku.size();i++){
        if(sudoku[row][i] == val){
            return false;
        }
        if(sudoku[i][col] == val){
            return false;
        }
        if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3] == val){
            return false;
        }
    }
    return true;
} 

bool solveSudoku(vector<vector<int>>& sudoku){
   int n = sudoku[0].size();
    for(int i = 0;i<n;i++){
        for(int j =0;j<n;j++){
            if(sudoku[i][j] == 0){
                for(int val = 1;val<=9;val++){
                    if(isSafe(sudoku,val,i,j)){
                        sudoku[i][j] =val;
                        bool ans = solveSudoku(sudoku);
                        if(ans){
                            return true;
                        } else {
                            sudoku[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }return true;
}

int main(){
vector<vector<int>> sudoku = {{3 ,0 ,6 ,5 ,0 ,8 ,4 ,0 ,0},
                              {5 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
                              {0 ,8 ,7 ,0 ,0 ,0 ,0 ,3 ,1},
                              {0 ,0 ,3 ,0 ,1 ,0 ,0 ,8 ,0},
                              {9 ,0 ,0 ,8 ,6 ,3 ,0 ,0 ,5},
                              {0 ,5 ,0 ,0 ,9 ,0 ,6 ,0 ,0},
                              {1 ,3 ,0 ,0 ,0 ,0 ,2 ,5 ,0},
                              {0 ,0 ,0 ,0 ,0 ,0 ,0 ,7 ,4},
                              {0 ,0 ,5 ,2 ,0 ,6 ,3 ,0 ,0}
};

if(solveSudoku(sudoku)){
    cout<<"Solved Successfully !"<<endl;
}else{
    cout<<"Not Solved "<<endl;
}


int n = sudoku[0].size();

for(int i = 0;i<n;i++){
        for(int j =0;j<n;j++){
            cout<<sudoku[i][j]<<" ";
    }cout<<endl;
}

return 0;
}