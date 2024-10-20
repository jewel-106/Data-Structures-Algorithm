
#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Fread freopen("input.txt", "r", stdin);
#define Fout freopen("output.txt", "w", stdout);
using namespace std;
using namespace __gnu_pbds;

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

typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;




int main()
{
#ifndef ONLINE_JUDGE
    Fread
    Fout
 #endif
    pbds A;

    // Inserting element 
    A.insert(1);
    A.insert(10);
    A.insert(2);
    A.insert(7);
    A.insert(2);

    // A contains
    cout<<"A = ";
    for(auto i: A)
        cout<<i<<" ";
    cout<<endl<<endl;

    // finding kth element 
    cout<<"0th element: "<<*A.find_by_order(0)<<endl;
    cout<<"1st element: "<<*A.find_by_order(1)<<endl;
    cout<<"2nd element: "<<*A.find_by_order(2)<<endl;
    cout<<"3rd element: "<<*A.find_by_order(3)<<endl;

    // finding number of elements smaler than x 
    cout<<"No. of elements smaller than 6: "<<A.order_of_key(6)<<endl;
    cout<<"No. of elements smaller than 11: "<<A.order_of_key(11)<<endl;
    cout<<"No. of elements smaller than 1: "<<A.order_of_key(1)<<endl;

    // lower bound -> Lower Bound of x = first element >= x in the set
    cout<<"Lower Bound of 6: "<<*A.lower_bound(6)<<endl;
    cout<<"Lower Bound of 2: "<<*A.lower_bound(2)<<endl;
    cout<<endl;
    // upper bound -> Upper Bound of x = first element > x in the set
    cout<<"Upper Bound of 6: "<<*A.upper_bound(6)<<endl;
    cout<<"Upper Bound of 1: "<<*A.upper_bound(1)<<endl;


    // Remove elements 
    A.erase(1);
    A.erase(11); // element that is not present is not affected

    cout<<"A = ";
    for(auto i: A)
        cout<<i<<" ";
    cout<<endl;


}