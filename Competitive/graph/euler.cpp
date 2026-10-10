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

int n, m = 0, root = 1;
int h[MAX], st[MAX], en[MAX], tour[MAX];
vector<int> adj[MAX];

void input()
{
    cin >> n;
    FOR(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}
void add(int u)
{
    tour[++m] = u;
    en[u] = m;
}

void dfs(int u, int par)
{
    h[u] = h[par] + 1;
    add(u);
    st[u] = m;
    for (auto v : adj[u])
    {
        if (v != par)
        {
            dfs(v, u);
            add(u);
        }
    }
}

signed main()
{
    fast_io;
    input();
    dfs(root, 0);
    return 0;
}

// Tính chất:
//  -u, v 0 thuộc cây con của nhau, 0 chung tổ tiên: en[u]<st[v] hoặc en[v]<st[u]
//  -v thuộc cây con gốc u: st[u]<st[v]<en[v]<en[u]