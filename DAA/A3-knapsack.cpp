#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n) {
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    while (!(cin >> n) || n <= 0) {
        cout << "Invalid input. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int profit[n], weight[n];

    for (int i = 0; i < n; ++i) {
        string input;
        int itemWeight, itemProfit;

        cout << "Enter weight for item " << i + 1 << ": ";
        while (true) {
            cin >> input;
            if (isdigit(input[0])) {
                itemWeight = stoi(input);
                weight[i] = itemWeight;
                break;
            } else {
                cout << "Invalid input. Please enter a number: ";
            }
        }

        cout << "Enter profit for item " << i + 1 << ": ";
        while (true) {
            cin >> input;
            if (isdigit(input[0])) {
                itemProfit = stoi(input);
                profit[i] = itemProfit;
                break;
            } else {
                cout << "Invalid input. Please enter a number: ";
            }
        }
    }

    int W;
    cout << "Enter the knapsack weight: ";
    while (!(cin >> W) || W <= 0) {
        cout << "Invalid input. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Maximum profit earned: " << knapSack(W, weight, profit, n);

    return 0;
}


/*
wt: {1,2,4,5}
pr: {5,4,8,6}
W: 5
ANS: 13

wt: {10,20,30}
pr: {60,100,120}
W:50
ANS: 220

*/
