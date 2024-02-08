#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int paren[N];
int dsize[N];
void initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        paren[i] = -1;
        dsize[i] = 1;
    }
}
int find_paren(int n)
{
    if (paren[n] == -1)
        return n;
    int leader = find_paren(paren[n]);
    paren[n] = leader;
    return leader;
}
void dsu_unio_by_size(int i, int j)
{
    int leaderA = find_paren(i);
    int leaderB = find_paren(j);
    if (dsize[leaderA] > dsize[leaderB])
    {
        paren[leaderB] = leaderA;
        dsize[leaderA] += dsize[leaderB];
    }
    else
    {
        paren[leaderA] = leaderB;
        dsize[leaderB] += dsize[leaderA];
    }
}
class edg
{
public:
    int a, b, w;
    edg(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
bool cmp(edg a, edg b)
{
    return a.w < b.w;
}
int main()
{
    int n, e;
    cin >> n >> e;
    initialize(n);
    vector<edg> edglist;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edglist.push_back(edg(a, b, w));
    }
    sort(edglist.begin(), edglist.end(), cmp);
    int cost = 0;
    for (edg ud : edglist)
    {
        // cout << ud.a << " " << ud.b << " " << ud.w << endl;
        int leaderA = find_paren(ud.a);
        int leaderB = find_paren(ud.b);
        if (leaderA == leaderB)
        {
            continue;
        }
        else
        {
            dsu_unio_by_size(leaderA, leaderB);
             cost += ud.w;
        }
    }
    cout << cost;
    return 0;
}