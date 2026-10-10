#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define pii pair<int, int>
#define piii pair<pair<int, int>, int>
#define pll pair<ll, int>
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
#define MAX 100005
const ll mod = 1e9 + 7;
const int infi = 1e9 + 7;

struct Edge
{
    int u, v;
    ll w;
};

int n, m;
vector<Edge> adj;
ll d[MAX];
int trace[MAX];

void belmanford(int s)
{
    FOR(i, 1, n - 1)
    {
        bool diff = false;
        for (auto e : adj)
        {
            if (d[e.u] > d[e.v] + e.w)
            {
                d[e.u] = d[e.v] + e.w;
                diff = true;
                trace[e.u] = e.v;
            }
        }
        if (!diff)
            break;
    }
}

void solve()
{
    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj.pb({u, v, w});
    }
    FOR(i, 1, n)
    {
        d[i] = infi;
        trace[i] = -1;
    }
    d[1] = 0;
    belmanford(1);
    int negStart = -1;
    for (auto e : adj)
    {
        if (d[e.u] != infi && d[e.v] > d[e.u] + e.w)
        {
            negStart = e.v;
            trace[e.v] = e.u;
            break;
        }
    }
    if (negStart != -1)
    {
        cout << "NEGATIVE CYCLE\n";
        return;
    }
    if (d[n] == infi)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    else
    {
        cout << d[n] << '\n';
    }
}

signed main()
{
    fast_io;
    solve();
}