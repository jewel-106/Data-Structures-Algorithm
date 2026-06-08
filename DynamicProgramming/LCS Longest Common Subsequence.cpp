
#include <bits/stdc++.h>
#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Fread freopen("input.txt", "r", stdin);
#define Fout freopen("output.txt", "w", stdout);
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define YES cout <<"YES\n"
#define NO cout << "NO\n"
#define nn '\n'
#define LL_INF (1LL << 62)
#define INF (1 << 30)
#define SetBit(x, k) (x = (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x >> k) & 1)

#define mod 998244353
#define N 300005
#define pi acos(-1.0)                                     

//Longest Common Subsequence
int longestCommonSubsequence(string s, string t){
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}
// space optimized version
int longestCommonSubsequence(string s, string t){
    int n = s.size();
    int m = t.size();

    vector<int> prev(m+1, 0), curr(m+1, 0);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1] == t[j-1]){
                curr[j] = 1 + prev[j-1];
            }
            else{
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }

    return prev[m];
}
int main()
{
#ifndef ONLINE_JUDGE
    Fread
    Fout
 #endif
    int t;
    cin>>t;
    while(t--){
        string s, t;
        cin>>s>>t;
        cout<<longestCommonSubsequence(s, t)<<endl;
    }
}