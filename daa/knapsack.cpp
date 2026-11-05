#include <iostream>
using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int val[100];
    int wt[100];

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int dp[101][101];

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    
    for (int w = 0; w <= W; w++) {
        dp[0][w] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                int includeItem = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                int excludeItem = dp[i - 1][w];

                if (includeItem > excludeItem) {
                    dp[i][w] = includeItem;
                } else {
                    dp[i][w] = excludeItem;
                }
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum Profit = " << dp[n][W] << endl;

    return 0;
}