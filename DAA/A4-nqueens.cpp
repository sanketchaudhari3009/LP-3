#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **arr, int x, int y, int n){
    for(int row = 0; row < x; row++)
    {
        if(arr[row][y]==1){
            return false;
        }
    }

    int row = x;
    int col = y;
    while(row >= 0 && col >= 0)
    {
        if(arr[row][col]==1)
            return false;
        
        row--;
        col--;
    }

    row =x;
    col =y;
    
    while(row >= 0 && col < n)
    {
        if(arr[row][col]==1)
            return false;
        
        row--;
        col++;
    }

    return true;
}

void printBoard(int **arr, int n){
	for(int i = 0; i < n; i++)
	{
        for(int j = 0; j < n; j++)
        {
			if(arr[i][j] == 1) 
			    cout << "[Q]";
			else 
			    cout << "[]";
		}
        cout << endl;
	}
	cout << endl;
	cout << endl;
}


void nQueen(int** arr, int x, int n){
    if(x == n)
    {
        printBoard(arr, n);
		return;
    }

    for(int col = 0; col < n; col++)
    {
        if(isSafe(arr,x,col,n))
        {
            arr[x][col] = 1;
            nQueen(arr,x+1,n);
            arr[x][col] = 0;
        }
    }
}


int main(){
    int n;
    cout << "Enter the board size (N): ";
    while (!(cin >> n) || n < 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive integer: ";
    }
    
    int **arr = new int*[n];    
    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
	
	cout << "All possible solutions: \n";
	nQueen(arr, 0, n);
	
	
	
    return 0;
}

/*
Output:
4
[][Q][][]
[][][][Q]
[Q][][][]
[][][Q][]


[][][Q][]
[Q][][][]
[][][][Q]
[][Q][][]


TC: O(N!)
SC: O(N^2)
*/