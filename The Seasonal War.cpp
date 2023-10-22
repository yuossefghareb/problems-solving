// problem https://vjudge.net/problem/UVA-352

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
const int N = 30;

int dx[8] = {0,0,1,-1,1,-1,1,-1};
int dy[8] = {1,-1,0,0,1,-1,-1,1};
int n;
int vis[N][N];
vector<string>g;
void dfs(int ur,int uc)
{
    vis[ur][uc]=1;

    for(int k=0;k<8;k++)
    {
        int nr=ur+dx[k];
        int nc=uc+dy[k];

        if(nr<0||nc<0||nr>=n||nc>=n)
            continue;
        if(vis[nr][nc]||g[nr][nc]=='0')
            continue;
        dfs(nr,nc);
    }

}

void solve()
{
int T=1;
   while(cin>>n)
   {
      
g=vector<string>(n);
memset(vis,0,sizeof(vis));
for(int i=0;i<n;i++)
       cin>>g[i];

int c=0;
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
{
    if(!vis[i][j]&&g[i][j]=='1')
    {
        dfs(i,j);
        c++;
    }
}
cout<<"Image number "<<T++<<" contains "<<c<<" war eagles.\n";

   }

}


signed main()
{
   // fast
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
