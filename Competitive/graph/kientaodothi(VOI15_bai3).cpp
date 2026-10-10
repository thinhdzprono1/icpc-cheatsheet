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
#define MAX 2000005
const ll mod = 1e9 + 7;
const int infi = 1e9;
#define int ll

int n, m;
vector<int> adj[100007];
int num[100007], low[100007], sz[100007];
int timeDfs, bridge, cc_nodes, ans_bridges;

void dfs(int u, int pre)
{
    num[u] = low[u] = ++timeDfs;
    sz[u] = 1;
    cc_nodes++;
    for (auto v : adj[u])
    {
        if (v == pre)
            continue;
        if (!num[v])
        {
            dfs(v, u);
            sz[u] += sz[v];
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v])
            {
                bridge++;
                ans_bridges += sz[v] * (n - sz[v]) - 1;
            }
        }
        else
        {
            low[u] = min(low[u], num[v]);
        }
    }
}

void solve()
{
    cin >> n >> m;
    timeDfs = bridge = cc_nodes = ans_bridges = 0;
    FOR(i, 1, n)
    {
        adj[i].clear();
        num[i] = low[i] = sz[i] = 0;
    }
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int cc_cnt = 0;
    vector<int> cc_size;
    FOR(i, 1, n)
    {
        if (!num[i])
        {
            cc_cnt++;
            cc_nodes = 0;
            dfs(i, i);
            cc_size.pb(cc_nodes);
        }
    }
    if (cc_cnt >= 3)
    {
        cout << 0 << '\n';
        return;
    }
    else if (cc_cnt == 2)
    {
        int add = cc_size[0] * cc_size[1];
        int remove = m - bridge;
        cout << add * remove << '\n';
        return;
    }
    else if (cc_cnt == 1)
    {
        int max_edges = n * (n - 1) / 2;
        int add = max_edges - m;
        int remove = m - bridge;
        cout << add * remove + ans_bridges << '\n';
        return;
    }
}

signed main()
{
    fast_io;
    solve();
}