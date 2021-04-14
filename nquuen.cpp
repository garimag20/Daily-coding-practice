#include<bits\stdc++.h>
using namespace std;

const int n = 4;
int grid[n][n];

bool is_safe(int row, int col){
    int i = row, j = col;
    //vertical check, row--, j
    while(i >= 0){
        if(grid[i][j] == 1)
            return false;
        i--;
    }
    //left diagonal check, i-- , j--
    i = row, j = col;
    while(i>=0 && j >= 0){
        if(grid[i][j] == 1)
            return false;
        i--;
        j--;
    }
    //right diagonal check, i-- , j++
    i = row, j = col;
    while(i>=0 && j < n){
        if(grid[i][j] == 1)
            return false;
        i--;
        j++;
    }
    return true;
}

void print_grid(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout<<(grid[i][j] ? "Q":".")<<" ";
        cout<< endl;
    }
}
void nqueen(int row){
    if(row == n){
        print_grid();
        return;
    }
    for(int col = 0; col < n; col++){
        //grid[row][col]
        // <row are completely filled
        // try and place queen on this cell
        if(is_safe(row, col)){
            grid[row][col] = 1;
            nqueen(row+1);
            //backtrack
            grid[row][col] = 0;
        }
    }
}

int main(){
    nqueen(0);
    return 0;
}