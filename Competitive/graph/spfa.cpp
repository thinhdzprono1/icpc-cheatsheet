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
const ll infi = 1e18;

vector<pii> adj[MAX];
int in_queue[MAX];
int d[MAX], cnt[MAX];
int s, n;
queue<int> q;

bool spfa()
{
    FOR(i, 1, n)
    {
        d[i] = infi;
        in_queue[i] = 0;
        cnt[i] = 0;
    }
    d[s] = 0;
    q.push(s);
    in_queue[s] = 1;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        in_queue[u] = 0;
        for (auto tmp : adj[u])
        {
            int v = tmp.fi;
            int w = tmp.se;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if (in_queue[v] == 0)
                {
                    q.push(v);
                    in_queue[v] = 1;
                    cnt[v]++;
                    if (cnt[v] >= n)
                        return false;
                }
            }
        }
    }
    return true;
}