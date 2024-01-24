// Search in the dictionary!
// https://vjudge.net/problem/SPOJ-DICT

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node{

bool isword=false;
Node* next[26]{};

void insert (string &s)
{
    Node* current=this;
    for(auto c:s)
    {
        int i=c-'a';
        if(current->next[i]==nullptr)
            current->next[i]=new Node;
        current=current->next[i];
    }
    current->isword=true;
}
vector<string>get(string s)
{

    Node *current=this;
    for(auto c:s)
    {
        int i=c-'a';
        if(!current->next[i])
           return {};
        current=current->next[i];
    }
    vector<string>ans;
    dfs(s,current,ans);
    return ans;
}
void dfs(string &s,Node* current,vector<string>&ans)
{
    for (int i=0;i<26;i++)
    {

        if(not current->next[i])
            continue;
         s+=(char)(i+'a');
        if (current->next[i]->isword)
                ans.push_back(s);
        dfs(s,current->next[i],ans);
        s.pop_back();

    }
}

bool contains(string &s,bool prefix=false)
{
    Node* current=this;
    for(auto c:s)
    {
        int i=c-'a';
        if(current->next[i]==nullptr)
            return false;
        current=current->next[i];
    }
    return prefix or current->isword;
}


};


int main()
{
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   // freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
   
   int n;cin>>n;
 Node trie;

 for(int i=0;i<n;i++)
 {
string s;cin>>s;
  trie.insert(s);
 }

 int q;cin>>q;
 for(int f=1;f<=q;f++)
 {
     cout<<"Case #"<<f<<":"<<'\n';
     string s;cin>>s;
     auto ans=trie.get(s);
    if(ans.empty())
        cout<<"No match.\n";
    else
    {
        for (auto s:ans)
            cout<<s<<'\n';
    }
 }

}
