#include <bits/stdc++.h>
using namespace std;

vector<int> fibdp(int n) {
    vector<int> dp(n+1,0);

    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp;
}

int fibRec(int n) {
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    return fibRec(n-1) + fibRec(n-2);
}

int main() {
    int n;
    cout<<"Enter Number : ";
    cin>>n;

    vector<int> result = fibdp(n);
    for(int x : result) {
        cout<<x<<endl;
    }

    cout<<endl;


}