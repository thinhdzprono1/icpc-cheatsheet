
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
#define MAX 1005
const ll mod = 1e9 + 7;
const ll infi = 1e18;
#define int ll

int n;
string s;

void solve()
{
    cin >> n >> s;
    int cnt = 0;
    if (s[0] == '1')
    {
        int cnt = 0;
        FOR(i, 1, n - 1)
        {
            if (s[i] == '0')
                cnt++;
        }
        cout << cnt << '\n';
        return;
    }
    int cnt_0 = 0;
    FOR(i, 0, n - 1)
    {
        if (s[i] == '0')
            cnt_0++;
    }
    int ans = cnt_0, suffix_0 = cnt_0, cnt_1 = 0;
    FOR(i, 0, n - 1)
    {
        if (s[i] == '0')
            suffix_0--;
        else
        {
            cnt_1++;
        }
        ans = min(ans, cnt_1 + suffix_0);
    }
    cout << ans << '\n';
}
signed main()
{
    fast_io;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}