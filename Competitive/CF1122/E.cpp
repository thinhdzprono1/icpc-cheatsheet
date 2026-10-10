
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define pii pair<int, int>
#define piii pair<pair<int, int>, int>
#define vi vector<int>
#define vs vector<string>
#define si set<int>
#define ss set<string>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define bong() main()
#define ALL(a) a.begin(), a.end()
#define mem(a, b) memset(a, b, sizeof(a))
inline ll gcd(ll a, ll b)
{
    ll r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
#define MAX 200005
const ll mod = 1e9 + 7;
const ll infi = 1e18;
#define int ll

int n, k;
int spf[MAX];

void sieve()
{
    for (int i = 2; i < MAX; i++)
        spf[i] = i;
    for (int i = 2; i * i < MAX; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAX; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

void solve()
{
    cin >> n >> k;
    vector<int> a;
    int max_val = -1e18;
    FOR(i, 1, n)
    {
        int x;
        cin >> x;
        a.pb(x);
        max_val = max(max_val, x);
    }
    if (max_val <= k)
    {
        cout << 0 << '\n';
        return;
    }
    vector<int> dp(max_val + 1, 0);
    for (int i = k + 1; i <= max_val; i++)
    {
        dp[i] = 1e18;
        int tmp = i;
        while (tmp > 1)
        {
            int p = spf[tmp];
            dp[i] = min(dp[i], 1 + p * dp[i / p]);
            while (tmp % p == 0)
                tmp /= p;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += dp[a[i]];
    }
    cout << ans << '\n';
    return;
}

signed main()
{
    fast_io;
    int t;
    cin >> t;
    sieve();
    while (t--)
    {
        solve();
    }
}