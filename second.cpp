#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define pb push_back
#define btoi(s1) stoi(s1, nullptr, 2)
#define itob(x) bitset<32>(x).to_string()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define xx first
#define yy second

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
const int INF = 1e9 + 7;

typedef vector<bool> vb;
typedef vector<string> vs;
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;
typedef map<int, int> mii;

template <typename T>
void input(vector<T> &v, int n)
{
    T x;
    rep(i, 0, n)
    {
        cin >> x;
        v.pb(x);
    }
}

int ans = INT_MIN;
int dfs(vector < vector<pair<int, int>>> graph, map<int, int> &mpp,int i)
{
    int a = 0,b = 0;

    for(auto x:graph){
        if(f){
            a = dfS(graph,mpp,x.first);
            continue;
        }
        b = dfs(graph,mpp,x.first);
    }

    int val = max(a,b);

    int temp = max(graph[i].second, graph[i].second + max(a, b));
    ans = max(ans, max(temp, graph[i].second + val));

    return ans;
}

int maxPathSum(vector<int> par,vector<int> values)
{
    int n = values.size();

    vector<vector<pair<int,int>>> graph(n);

    for(int i=1;i<par.size();i++){
        graph[par[i]].push_back({i,value[i]});
    }

    map<int, int> mpp;

    return dfs(graph, mpp,0);

}

signed main()
{
    fast;

    // cout<<fixed<<setprecision(10);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
