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

void solve(){
    int k,x;
    cin>>k>>x;

    int n = k*(k+1)/2;

    // cout<<n<<endl;

    if(n == x)
    {
        cout<<k<<endl;
    }

    else if(n > x){
        int s = 1,e = k-1;
        int ans = k;
        while(s<=e){
            int mid = (s+e)/2;
            int a = mid*(mid+1)/2;
            if(a == x){
                ans= mid;
                break;
            }
            if(a<x){
                s = mid+1;
            }
            else{
                ans = mid;
                e = mid-1;
            }
        }

        cout<<ans<<endl;
    }

    else{
        int s = k+1,e=2*1L*k-1;
        int ans = k;
        int t = 2*k;

        while(s<=e){
            int mid = (s+e)/2;
            int j = t - mid;

            int p1 = k*(k-1)/2;
            int o = j*(j-1)/2;

            int a = p1-o;
            int g = a+n;

            if(g<x){
                s=mid+1;
            }
            else if(g == x){
                ans = mid;
                break;
            }
            else{
                ans = mid;
                e = mid-1;
            }
        }

        cout<<ans<<endl;
    }
}

signed main()
{
//     fast;
    //no need for fast

    // cout<<fixed<<setprecision(10);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
