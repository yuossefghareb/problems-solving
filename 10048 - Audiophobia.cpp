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
constexpr ll OO =  0x3f3f3f3f3f3f3f3f;
const int MOD =  1e9;
const int N = 105;

ll dist[N][N];





void solve()
{
int T=1;
while(1){
    int n,m,q;
    cin>>n>>m>>q;
    if(n==0&&m==0&&q==0)
        break;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            dist[i][j]=OO;
    for(int i=0; i<m; i++)
    {
        int u,v,c;
        cin>>u>>v>>c;

        dist[u][v]=c;
        dist[v][u]=c;

    }

    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                {
                   dist[i][j]=min(dist[i][j],max(dist[i][k],dist[k][j]));

                }
      if(T!=1)
                    cout<<el;
  cout<<"Case #"<<T++<<el;
while(q--)
{
    int a,b;cin>>a>>b;
    if(dist[a][b]<OO)
        cout<<dist[a][b]<<'\n';
    else
    cout<<"no path\n";

}

}



}


signed main()
{
    fast
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
//
    // cin>>t;
    for(int ii=1; ii<=t; ii++)
    {
        //  cout<<"Case #"<<ii<<": ";
        solve();
        // cout<<el;

    }

}
