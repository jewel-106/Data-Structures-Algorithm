
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
// DFS
int vis[10000];
void dfs(vector<vector<int>>& adj,int node)
{
    vis[node]=1;
    cout<<node<<"->";
    for(int i=0;i<adj[node].size();i++)
    {
        int child = adj[node][i];
        if(vis[child]==0)
        {
            dfs(adj,child);
        }
    }
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
        int V,E;
        cin>>V>>E;

        vector<vector<int>> adj(V);

        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(adj,0);

    }
}