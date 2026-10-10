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
const ll infi = 1e18;
#define int ll

int n, m, s;
vector<pii> adj[MAX];
int in_degree[MAX];
int d[MAX], trace[MAX];

void alg(int S)
{
    FOR(i, 1, n)
    {
        d[i] = infi;
        trace[i] = -1;
    }
    d[S] = 0;
    queue<int> q;
    FOR(i, 1, n)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto edge : adj[u])
        {
            int v = edge.fi;
            int w = edge.se;
            if (d[u] != infi)
            {
                if (d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                    trace[v] = u;
                }
            }
            in_degree[v]--;
            if (!in_degree[v])
            {
                q.push(v);
            }
        }
    }
}