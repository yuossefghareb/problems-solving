

// link  : https://vjudge.net/problem/UVA-10608




#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)

typedef long long         ll;

const double EPS = (1e-7);
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

#define pb					push_back
#define MP					make_pair
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;

const int MAX = 100;
bool valid(int i, int j) { 	return 1;	}
char maze[MAX][MAX];
bool vis[MAX][MAX];





int n, e;
vector< vector<int> > adj;
vector<bool> visited;
bool flag=1;
vector<int> topsort;
vector<int> start, finish;
bool anyCycle = 0;
int timer = 0;
int c=0;



void dfs(int node)
{
	visited[node] = true;
    c++;
	rep(i, adj[node])
	{
		int child = adj[node][i];
		if (!visited[child]){	// To avoid cyclic behavior
			dfs(child);

		}
	}


	topsort.push_back(node);	// DAG // Other way Indegree / Outdegree
}


int ConnectedComponenetsCnt()
{
	int cnt = 0;
	lp(i, n)
	{
		if(!visited[i])	// Then no one reach this isolated node yet and its neighbors.
		{
			dfs(i);
			cnt++;
		}
	}
	return cnt;
}




void dfs_EdgeClassification(int node)
{
	start[node] = timer++;

	rep(i, adj[node])
	{
		int child = adj[node][i];
		if (start[child] == -1)	// Not visited Before. Treed Edge
			dfs_EdgeClassification(child);
		else {
			if(finish[child] == -1)// then this is ancestor that called us and waiting us to finish. Then Cycle. Back Edge
				anyCycle = 1;
			else if(start[node] < start[child])	// then you are my descendant
				;	// Forward Edge
			else
				;	// Cross Edge
		}
	}

	finish[node] = timer++;
}







int main()
{
#ifndef ONLINE_JUDGE
	//freopen("c.in", "rt", stdin);
	//freopen(".txt", "wt", stdout);
#endif

int t;cin>>t;
	while(t--){
cin>>n>>e;
	adj = vector< vector<int> >(n);
	visited = vector<bool>(n,0);
  c=0;
	topsort.clear();

	lp(i, e) {
		int from, to;
		cin>>from>>to;
		adj[from-1].push_back(to-1);
		adj[to-1].push_back(from-1);
 	}
int mx=0;
for(int i=0;i<n;i++)
{
    c=0;
    if(!visited[i])
    {
        dfs(i);
        mx=max(mx,c);
        c=0;
    }
}
cout<<mx<<endl;




	}
	return 0;
}
