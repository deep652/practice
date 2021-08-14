#include <iostream>
#include "header1.h"
#include<vector>
using namespace std;

bool isSafe(int i, int j, int n, int m)
{
    if(i < n && j < m && i!=-1 && j!=-1)
    {
        return true;
    }
    return false;
}
bool isDestination(int i, int j, int n, int m)
{
    if(i == n-1 && j == m-1)
    {
        return true;
    }
    return false;
}
void printSol(vector<vector<int>> &sol)
{
    int n = sol.size();
    int m = sol[0].size();

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<sol[i][j]<<"\t";
        }
        cout<<endl;
    }
}
bool bk(int i, int j, int row, int col, vector<vector<int>>& grid, vector<vector<int>> &sol)
 {

     if(!isSafe(i, i, row, col) || grid[i][j] == -1)
     {
         return false;
     }
     if(isSafe(i, j, row, col) && isDestination(i, j, row, col) && grid[i][j] == 1)
     {
         sol[i][j]=1;
         return true;
     }
     if(isSafe(i, j, row, col) == true){
        if(sol[i][j] == 1)
            return false;

        sol[i][j] = 1;

        if(bk(i, j+1, row, col, grid, sol) == true)
            return true;

        if(bk(i+1, j, row, col, grid, sol) == true)
            return true;


        sol[i][j] = 0;
        return false;
     }

     return false;

 }
 void findWays(int n, int m, vector<vector<int>>grid){
	    vector<vector<int>> sol  = { { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 } };

        if(bk(0, 0, 4, 4, grid, sol) == true)
            printSol(sol);
        else
        {
            cout<<"solution doesn't exits";
        }

}

 int main()
{
    vector<vector<int>> grid = { { 1, 0, 0, 0 },
                    { 1, 1, 0, 1 },
                    { 0, 1, 0, 0 },
                    { 1, 1, 1, 1 } };

    findWays(4, 4, grid);
    return 0;
}

