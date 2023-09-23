#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back

#define ld long double
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define RT(x) return cout << x, 0
#define pi 3.1415926535897932384626433
#define outf(x) cout << fixed << setprecision(x)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define el '\n'
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
constexpr ll OO = 0x3f3f3f3f3f3f3f3f;
const int MOD =  1073741824;
const int N = 5e3+5;







vector<int>g[N];
bool vis[N];

int dfs(int u)
{
    int c=1;
    vis[u]=1;


    for(int v:g[u])
    {
        if(!vis[v])
        {
         c+= dfs(v);
        }
    }
    return c;

}

void solve()
{

int n,m;

while(true){
cin>>n>>m;

if(n==0&&m==0)
{
    break;
}

map<string,int>mp;
for(int i=0;i<n;i++)
{
    string s;
    cin>>s;
    mp[s]=i+1;
}
for(int i=0;i<m;i++)
{
    string  u,v;cin>>u>>v;
    g[mp[v]].push_back(mp[u]);
    g[mp[u]].push_back(mp[v]);

}
int mx=0;

for(int i=1;i<=n;i++)
{
    if(!vis[i])
    mx=max(mx,dfs(i));
}

cout<<mx<<el;

for(int i=1;i<=n;i++)
{
    g[i].clear();
    vis[i]=0;
}
}



}

int main()
{
    fast

    ll t=1;
   // cin>>t;
    while(t--)
    {
        solve();
      // cout<<el;

    }

}
