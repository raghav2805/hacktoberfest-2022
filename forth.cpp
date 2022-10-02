#include <bits/stdc++.h>
using namespace std;
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
void scan_algorithm(int left[], int right[], int count, int limit)
{
    int arr[20];
    int x = count - 1, y = count + 1, c = 0, d = 0, j;
    while (x > -1)
    {
        printf("\nX:\t%d", x);
        printf("\nLeft[X]:\t%d", left[x]);
        arr[d] = left[x];
        x--;
        d++;
    }
    arr[d] = 0;
    while (y < limit + 1)
    {
        arr[y] = right[c];
        c++;
        y++;
    }
    printf("\nScanning Order:\n");
    for (j = 0; j < limit + 1; j++)
    {
        printf("\n%d", arr[j]);
    }
}

void division(int elements[], int limit, int disk_head)
{
    int count = 0, p, q, m, x;
    int left[20], right[20];
    for (count = 0; count < limit; count++)
    {
        if (elements[count] > disk_head)
        {
            printf("\nBreak Position:\t%d\n", elements[count]);
            break;
        }
    }
    printf("\nValue:\t%d\n", count);
    q = 1;
    p = 0;
    m = limit;
    left[0] = elements[0];
    printf("\nLeft:\t%d", left[0]);
    while (q < count)
    {
        printf("\nElement[l] value:\t%d", elements[q]);
        left[q] = elements[q];
        printf("\nLeft:\t%d", left[q]);
        q++;
        printf("\nl:\t%d", q);
    }
    x = count;
    while (x < m)
    {
        right[p] = elements[x];
        printf("\nRight:\t%d", right[p]);
        printf("\nElement:\t%d", elements[x]);
        p++;
        x++;
    }
    scan_algorithm(left, right, count, limit);
}

void sorting(int elements[], int limit)
{
    int location, count, j, temp, small;
    for (count = 0; count < limit - 1; count++)
    {
        small = elements[count];
        location = count;
        for (j = count + 1; j < limit; j++)
        {
            if (small > elements[j])
            {
                small = elements[j];
                location = j;
            }
        }
        temp = elements[location];
        elements[location] = elements[count];
        elements[count] = temp;
    }
}

signed main()
{
    int count, disk_head, limit;
    printf("Enter total number of locations:\t");
    scanf("%d", &limit);
    int elements[limit];

    printf("\nEnter position of disk head:\t");
    scanf("%d", &disk_head);
    printf("\nEnter elements of disk head queue\n");
    for (count = 0; count < limit; count++)
    {
        printf("Element[%d]:\t", count + 1);
        scanf("%d", &elements[count]);
    }
    sorting(elements, limit);
    division(elements, limit, disk_head);

    return 0;
}