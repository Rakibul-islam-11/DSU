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
        dsize[leaderA] = +dsize[leaderB];
    }
    else
    {
        paren[leaderA] = leaderB;
        dsize[leaderB] += dsize[leaderA];
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    initialize(n);
    bool ans=false;
    while(e--){
        int a,b;
        cin>>a>>b;
        if(find_paren(a)==find_paren(b)){
            ans=true;
            continue;
        }else{
            dsu_unio_by_size(a,b);
        }
    }
    if(ans==true){
        cout<<"Cycle is found";
    }else {
        cout<<"Cycle in not found";
    }
    return 0;
}