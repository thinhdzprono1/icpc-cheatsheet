#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, int> // Cấu trúc: {khoảng cách, đỉnh}
#define fi first
#define se second

const int MAX = 100005;
const ll INF = 1e18;

int n, m;
vector<pair<int, ll>> adj[MAX]; // Cấu trúc: {đỉnh đích, trọng số}
ll d[MAX];

void dijkstra(int s)
{
    // 1. Khởi tạo
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }
    d[s] = 0;

    // 2. Khai báo Min-Heap
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});

    // 3. Loang và nới lỏng
    while (!pq.empty())
    {
        ll du = pq.top().fi;
        int u = pq.top().se;
        pq.pop();

        // Lazy Deletion: Chốt chặn dọn rác
        if (du > d[u])
            continue;

        for (auto edge : adj[u])
        {
            int v = edge.fi;
            ll w = edge.se;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({d[v], v}); // Đẩy trạng thái tốt hơn vào hàng đợi
            }
        }
    }
}