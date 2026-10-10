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

int n, m, s;
vector<int> adj[MAX];
int num[MAX], low[MAX];
vector<int> adj[MAX];
bool deleted[MAX];
int timeDfs, team[MAX], team_cnt;
stack<int> st;

void dfs(int u)
{
    num[u] = low[u] = ++timeDfs;
    st.push(u);
    for (auto v : adj[u])
    {
        if (deleted[v])
            continue;
        if (!num[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else
        {
            low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u])
    {
        int v;
        do
        {
            v = st.top();
            st.pop();
            deleted[v] = true;
            team[v] = team_cnt;
        } while (v != u);
        team_cnt++;
    }
}

void solve()
{
    cin >> n >> m >> s;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    FOR(i, 1, n)
    {
        if (!num[i])
        {
            dfs(i);
        }
    }
    vector<int> in_degree(team_cnt - 1, 0);
    FOR(u, 1, team_cnt - 1)
    {
        for (auto v : adj[u])
        {
            if (team[u] != team[v])
            {
                in_degree[team[v]]++;
            }
        }
    }
    int ans = 0;
    FOR(i, 1, team_cnt - 1)
    {
        if (in_degree[i] == 0 && i != team[s])
            ans++;
    }
    cout << ans << '\n';
}