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
                                      \
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
#define MAX 1005
const ll mod = 1e9 + 7;
const ll infi = 1e18;
// #define int ll

// iostream, vector and queue are included
// Hint: use breadth-first-search

struct Node
{
    int data;
    Node *next;
};

void reverse(Node *head)
{
    Node *cur = head;
    Node *prev = nullptr;
    Node *late = nullptr;
    while (cur->next != nullptr)
    {
        late = cur->next;
        cur->next = prev;
        prev = cur;
        cur = late;
    }
    head = cur;
}

int main()
{
    fast_io;
    
}
