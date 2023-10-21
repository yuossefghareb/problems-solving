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
constexpr ll OO =  1e18;
const int MOD =  1e9;
const int N = 504;

ll dist[N][N];





void solve()
{

    int n;
    cin>>n;
  int xx=0;
    for(ll i=1; i<n; i++)
    {
        for(ll j=0; j<i; j++)
        {

            string x;
            cin>>x;
            if(x=="x")
                dist[i][j]=dist[j][i]=OO;
            else
            {
                dist[i][j]=dist[j][i]=stoi(x);
            }
        }
    }



    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

    ll ans=0;
    for(int i=1; i<n; i++)
        ans=max(dist[0][i],ans);

    cout<<ans<<el;




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
