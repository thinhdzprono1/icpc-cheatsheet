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

int num[1007], low[1007];
vector<int> adj[1007];
int timeDfs = 0, joint_count = 0, bridge_count = 0;
int child_count = 0; // Dành riêng cho gốc

void dfs(int u, int pre)
{
    num[u] = low[u] = ++timeDfs;
    bool is_joint = false;

    for (int v : adj[u])
    {
        if (v == pre)
            continue;
        if (!num[v])
        { // Đỉnh v chưa thăm -> Cạnh cây
            if (u == pre)
                child_count++; // Đếm số lính của Gốc, nếu 1 lính thì không phải khớp

            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] == num[v])
                bridge_count++; // TÌM THẤY CẦU (không có đường tắt nối ngược nào nhanh hơn)
            if (low[v] >= num[u])
                is_joint = true; // TÌM THẤY KHỚP (đường tắt của của v thấp hơn u->u là khớp)
        }
        else
        { // Đỉnh v đã thăm -> Cạnh ngược
            low[u] = min(low[u], num[v]);
        }
    }
    // Chốt sổ xem u có phải là Khớp không
    if ((u == pre && child_count > 1) || (u != pre && is_joint))
    {
        joint_count++;
    }
}
