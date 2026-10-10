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

int n, m;
vector<int> adj[100005];
int team[100005];

void solve()
{
    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    FOR(i, 1, n)
    {
        if (team[i] == 0)
        {
            queue<int> q;
            q.push(i);
            team[i] = 1;
            while (q.size())
            {
                int curr = q.front();
                q.pop();
                for (int x : adj[curr])
                {
                    if (team[x] == 0)
                    {
                        team[x] = 3 - team[curr];
                        q.push(x);
                    }
                    else
                    {
                        if (team[curr] == team[x])
                        {
                            cout << "IMPOSSIBLE\n";
                            return;
                        }
                    }
                }
            }
        }
    }
    FOR(i, 1, n)
    cout << team[i] << ' ';
    cout << '\n';
}

signed main()
{
    fast_io;
    solve();
}