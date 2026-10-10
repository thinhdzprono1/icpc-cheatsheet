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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
char grid[1005][1005];
int dist[1005][1005];
int R, C;

void solve()
{
    cin >> R >> C;
    FOR(i, 1, R)
    {
        FOR(j, 1, C)
        {
            cin >> grid[i][j];
            dist[i][j] = infi;
        }
    }
    dist[1][1] = 0;
    deque<pii> dq;
    dq.push_front({1, 1});
    while (dq.size())
    {
        pii curr = dq.front();
        dq.pop_front();
        FOR(i, 0, 3)
        {
            int nx = curr.fi + dx[i];
            int ny = curr.se + dy[i];
            if (nx >= 1 && nx <= R && ny >= 1 && ny <= C)
            {
                int w = (grid[nx][ny] == grid[curr.fi][curr.se] ? 0 : 1);
                if (dist[nx][ny] > dist[curr.fi][curr.se] + w)
                {
                    dist[nx][ny] = dist[curr.fi][curr.se] + w;
                    if (w == 0)
                    {
                        dq.push_front({nx, ny});
                    }
                    else
                        dq.pb({nx, ny});
                }
            }
        }
    }
    cout << dist[R][C] << '\n';
}

signed main()
{
    fast_io;
    int t;
    cin >> t;
    while (t--)
        solve();
}
