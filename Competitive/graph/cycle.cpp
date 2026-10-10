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
bool visited[100005];
int trace[100005];

void solve()
{
    cin >> n >> m;
    FOR(i, 1, n)
    {
        adj[i].clear();
        visited[i] = false;
        trace[i] = 0;
    }
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    FOR(i, 1, n)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            trace[i] = 0;
            while (q.size())
            {
                int u = q.front();
                q.pop();
                for (int v : adj[u])
                {
                    if (v == trace[u])
                        continue;
                    if (visited[v])
                    {

                        vector<int> path_u;
                        int curr = u;
                        while (curr != 0)
                        {
                            path_u.pb(curr);
                            curr = trace[curr];
                        }
                        vector<int> in_path_u(n + 1, false);
                        for (int node : path_u)
                            in_path_u[node] = true;
                        curr = v;
                        vector<int> path_v;
                        while (!in_path_u[curr])
                        {
                            path_v.pb(curr);
                            curr = trace[curr];
                        }
                        int lca = curr; // điểm chung
                        vector<int> cycle;
                        cycle.pb(v);
                        for (int node : path_u)
                        {
                            cycle.pb(node);
                            if (node == lca)
                                break;
                        }
                        for (int j = path_v.size() - 1; j >= 0; j--)
                        {
                            cycle.pb(path_v[j]);
                        }
                        cout << cycle.size() << '\n';
                        for (int node : cycle)
                            cout << node << " ";
                        cout << '\n';

                        return;
                    }
                    else
                    {
                        visited[v] = true;
                        trace[v] = u;
                        q.push(v);
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

signed main()
{
    fast_io;
    solve();
}