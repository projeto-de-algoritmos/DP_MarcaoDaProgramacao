// Cut Ribbon (similar to coin change problem)
// https://codeforces.com/problemset/problem/189/A

#include<bits/stdc++.h>
using namespace std;

int dp[3][4001];
int coins[3];

int solution(int n, int m){
	if(m <= 0){	
		return 0;
	}
	if(dp[n][m] != -1){
		return dp[n][m];	
	}
		
	int ans = INT_MIN;
    for(int i = 0; i <= n; i++) {
    	if(coins[i] <= m){
    		int temp = solution(n, m - coins[i]);
 			if(ans < temp+1)
 				ans = temp + 1;
 		}
 	}
 	return dp[n][m] = ans;
}

int main() {
	memset(dp, -1, sizeof(dp));
    int n;
    cin >> n >> coins[0] >> coins[1] >> coins[2];
    cout << solution(2, n);
    
    return 0;
}
