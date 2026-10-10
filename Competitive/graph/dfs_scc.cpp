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
#define MAX 2000005
const ll mod = 1e9 + 7;
const int infi = 1e9;

stack<int> st;
int scc_cnt;
bool deleted[MAX];
int timeDfs, num[MAX], low[MAX];
vector<int> adj[MAX];
void dfs_scc(int u)
{
    num[u] = low[u] = ++timeDfs;
    st.push(u);
    for (auto v : adj[u])
    {
        if (deleted[v])
            continue;
        if (!num[v])
        {
            dfs_scc(v);
            low[u] = min(low[u], low[v]);
        }
        else
        {
            low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u])
    {
        scc_cnt++;
        int v;
        do
        {
            v = st.top();
            st.pop();
            deleted[v] = true;
        } while (v != u);
    }
}