// problem https://vjudge.net/problem/UVA-352
#include<bits/stdc++.h>

using namespace std;

#define all(v)              ((v).begin()), ((v).end())
#define sz(v)               ((int)((v).size()))
#define clr(v, d)           memset(v, d, sizeof(v))
#define rep(i, v)       for(int i=0;i<sz(v);++i)
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)    for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)    for(int i=(j);i>=(int)(n);--i)
#define el '\n'
#define yes cout<<"YES"<<endl;
#define no  cout<<"NO"<<endl;

typedef long long         ll;

const double EPS = (1e-7);
int dcmp(double x, double y) {    return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;    }

#define pb                  push_back
#define MP                  make_pair
#define P(x)                cout<<#x<<" = { "<<x<<" }\n"
typedef long double          ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;

const int MAX = 30;
//bool valid(int i, int j) {    return i >= 0 && j >= 0 && i < n && j < n;    }
char maze[MAX][MAX];
bool vis[MAX][MAX];


int dx[8] = {0,0,1,-1,1,-1,1,-1};
int dy[8] = {1,-1,0,0,1,-1,-1,1};




int n, e;
vector< vector<int> > adj;
vector<bool> visited;
int parent[MAX],depth[100005];
vector<int> topsort;
vector<int> start, finish;
bool anyCycle = 0;
int timer = 0;

char grid[MAX][MAX];
bool viss[MAX][MAX];


/*
void dfs(int node)
{
    visited[node] = true;

    rep(i, adj[node])
    {
        int child = adj[node][i];
        if (!visited[child]){
              //  parent[child]=node;
              depth[child]=depth[node]+1;
            dfs(child);
        }
    }

    topsort.push_back(node);
}
*/
bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < n;
}
void dfs(int i,int j)
{
    if(viss[i][j])
        return;
    viss[i][j]=1;

    for(int k=0;k<8;k++)
    {
        int xc = dx[k] + i;
        int yc = dy[k] + j;
        if(valid(xc,yc) && !viss[xc][yc] && grid[xc][yc] == '1')
            dfs(xc,yc);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("c.in", "rt", stdin);
    //freopen(".txt", "wt", stdout);
#endif
int tc = 1;
	while(cin>>n){


    for(int i=0;i<n;i++)
    {
        cin>>grid[i];
    }

    int c=0;
    memset(viss,0,sizeof viss);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!viss[i][j] && grid[i][j]=='1')
            {
                dfs(i,j);
                c++;
            }
        }
    }
  printf("Image number %d contains %d war eagles.\n",tc++,c);
	}
    return 0;
}
