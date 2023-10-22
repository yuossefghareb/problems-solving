
// link : https://codeforces.com/problemset/gymProblem/101498/L

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
#define si(t) scanf("%d",&t)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define int long long
constexpr ll OO = 1e18;
const int MOD =  1e9;
const int N = 2e3+5;

ll dist[N];
int n;
vector<tuple<int,int ,ll>>es;


void solve()
{


int m;cin>>n>>m;
es.clear();
for(int i=1;i<=n;i++)
    dist[i]=OO;
for(int i=0;i<m;i++)
{
    int u,v,w;
    cin>>u>>v>>w;
    es.push_back({u,v,w});
  dist[v] = min(dist[v], 1ll * w);
}


        bool is_inf=0;
     for(int i=0;i<n;i++)
     {
         for(auto[u,v,w]:es)
         {
             if(dist[u]+w<dist[v])
             {

                 dist[v]=dist[u]+w;
               is_inf=(i+1==n);
             }
         }
     }


if(is_inf)cout<<"-inf"<<el;
else
{
    cout << *min_element(dist + 1, dist + n + 1) << '\n';
}


}


signed main()
{
   // fast
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
//
     cin>>t;
    for(int ii=1; ii<=t; ii++)
    {
        //  cout<<"Case #"<<ii<<": ";
        solve();
        // cout<<el;

    }

}
