// https://vjudge.net/problem/SPOJ-SHPATH
#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
constexpr ll OO = 0x3f3f3f3f3f3f3f3f;
const int N=1e4+4;
vector<pair<int,int>>g[N];
int dist[N],n;

void dij(int src)
{   for (int i = 0; i <= n; ++i)
         dist[i] = OO;
    dist[src]=0;

    priority_queue<pair<int,int>>p;
    p.push({0,src});
    while(not p.empty())
    {
        auto[c,u]=p.top();
        p.pop();
        c*=-1;
        if (dist[u] < c)
            continue;
        for(auto [w,v]:g[u])
        {
           if(w+c<dist[v])
           {
                dist[v] = dist[u] + w;
                p.push({-dist[v],v});
           }
        }

    }
}
void test_case()
{
  cin>>n;
  map<string,int>mp;
  for(int i=1;i<=n;i++)
  {
      string s;
      cin>>s;
      mp[s]=i;
      int p;cin>>p;
      while(p--)
      {
         int v,w;cin>>v>>w;
         g[i].push_back({w,v});
         g[v].push_back({w,i});
      }
  }

  int q;cin>>q;
  while(q--)
  {
      string s,c;cin>>s>>c;
      dij(mp[s]);
      cout<<dist[mp[c]]<<el;
  }
  for(int i=1; i<=n; i++) g[i].clear();
}

int main()
{
    fast
    int t=1;

      cin>>t;
    while(t--)
    {
        test_case();


    }


}
