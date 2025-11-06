#include <bits/stdc++.h>
using namespace std;

struct item {
    int value;
    int weight;
};

bool compare(item a, item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double KnapsackFraction(int W, vector<item> &arr) {
    sort(arr.begin(), arr.end(), compare);
    int currentWeight = 0;
    double finalValue = 0.0;

    for(auto& pair : arr) {
        if(currentWeight + pair.weight <= W) {
            currentWeight += pair.weight;
            finalValue += pair.value;
            cout<<finalValue<<" : "<<currentWeight<<endl;
        } else {
            int remain = W - currentWeight;
            finalValue += (double)pair.value * ((double)remain / pair.weight);
            break;
        }
    }
    return finalValue;
}

int knapsackDp(int n, int W, vector<int>& value, vector<int>& weight) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=W; j++) {
            if(weight[i-1] <= j) {
                dp[i][j] = max(value[i-1 + dp[i-1][j-weight[i-1]]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int W = 60, n = 5;
    vector<item> arr(n);
    for(int i = 0; i<n; i++) {
        cin>>arr[i].value>>arr[i].weight;
    }

    KnapsackFraction(W, arr);
}