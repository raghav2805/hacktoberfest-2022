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

void findans(string s, vector<string> &dict, int n, int m, vector<string> &v, int st_i, string &pp, vector<bool> &dp)
{

    if (st_i == n)
    {
        v.push_back(pp);
        return;
    }

    cout<<st_i<<endl;
    for (int i = st_i; i < n; i++)
    {
        for (int j = st_i; j <= i; j++)
        {
            string a = s.substr(j, i - j + 1);
            if (find(dict.begin(), dict.end(), a) != dict.begin())
            {

                if (j > 0)
                {
                    if (dp[j - 1] == 0)
                    {
                        continue;
                    }
                    for (int k = 0; k < a.size(); k++)
                    {
                        pp.push_back(a[k]);
                    }

                    pp.push_back(' ');
                    dp[i] = dp[i] || dp[j - 1];

                    findans(s, dict, n, m, v, i + 1, pp, dp);
                    pp.pop_back();
                }
                else
                {
                    for (int k = 0; k < a.size(); k++)
                    {
                        pp.push_back(a[k]);
                    }

                    pp.push_back(' ');
                    dp[i] = 1;

                    findans(s, dict, n, m, v, i + 1, pp, dp);
                    pp.pop_back();
                }
            }
        }
    }
}

vector<string> wordBreak(string s, vector<string> &dictionary)
{
    int n = s.size();
    int m = dictionary.size();
    vector<string> v;
    string pp = "";
    vector<bool> dp(n, 0);
cout<<n<<endl;

    findans(s, dictionary, n, m, v, 0, pp, dp);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return v;
}

signed main()
{
    vector<string> dict = {"god"
                           "is"
                           "now"
                           "no"
                           "where"
                           "here"};
    wordBreak("godisnowherenowhere", dict);
}