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

int A, B, C;

void solve()
{
    cin >> A >> B >> C;
    if (C > max(A, B) || C % gcd(A, B) != 0)
    {
        cout << -1 << '\n';
        return;
    }
    queue<pii> q;
    map<pii, int> dist;
    q.push({0, 0});
    dist[{0, 0}] = 0;
    while (q.size())
    {
        pii curr = q.front();
        q.pop();
        int a = curr.fi;
        int b = curr.se;
        if (a == C || b == C)
        {
            cout << dist[{a, b}] << '\n';
            return;
        }
        vector<pii> next_states;
        next_states.pb({0, b});
        next_states.pb({a, 0});
        next_states.pb({A, b});
        next_states.pb({a, B});
        next_states.pb({a - min(a, B - b), b + min(a, B - b)});
        next_states.pb({a + min(b, A - a), b - min(b, A - a)});
        for (auto state : next_states)
        {
            if (dist.find(state) == dist.end())
            {
                dist[state] = dist[{a, b}] + 1;
                q.push(state);
            }
        }
    }
    cout << -1 << '\n';
}

signed main()
{
    fast_io;
    int t;
    cin >> t;
    while (t--)
        solve();
}