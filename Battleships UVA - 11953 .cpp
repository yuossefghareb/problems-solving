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
const int N = 105;

int dx[8] = {0,0,1,-1,1,-1,1,-1};
int dy[8] = {1,-1,0,0,1,-1,-1,1};
vector<string>g;

int vis[N][N];


int n;
void dfs(int ur,int uc)
{
    vis[ur][uc]=1;

    for(int k=0;k<8;k++)
    {
        int nr=ur+dx[k];
        int nc=uc+dy[k];

        if(nr<0||nc<0||nr>=n||nc>=n)
            continue;
        if(vis[nr][nc]||g[nr][nc]=='.')
            continue;
        dfs(nr,nc);
    }

}
void solve()
{



    cin>>n;

    g=vector<string>(n);
    memset(vis,0,sizeof(vis));
    int c=0;
    for(int i=0; i<n; i++)
    {
        cin>>g[i];

    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
        {
            if(!vis[i][j]&&g[i][j]=='x')
            {
                c++;
                dfs(i,j);
            }
        }
    }

    cout<<c<<el;



}

int main()
{
    fast

    ll t=1;
    int z=1;
     cin>>t;
    while(t--)
    {
        cout<<"Case "<<z++<<": ";
        solve();
        // cout<<el;

    }

}
