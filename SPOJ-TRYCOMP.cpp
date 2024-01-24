
// Try to complete
// https://vjudge.net/problem/SPOJ-TRYCOMP

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<string> us;

struct Node{

int ans_cnt=0,idx=-1;

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
    if (current->idx == -1) {
        current->idx = (int) us.size();
        us.push_back(s);
    }
    current->ans_cnt++;
}
pair<int,int> get(string s)
{

    Node *current=this;
    for(auto c:s)
    {
        int i=c-'a';
        if(!current->next[i])
           return {-1,0};
        current=current->next[i];
    }

    
   return {current->idx,current->ans_cnt};
    
}


};

void dfs(Node* current)
{
    for (int i=0;i<26;i++)
    {
        if(not current->next[i])
            continue;
        dfs(current->next[i]);
        if(current->ans_cnt< current->next[i]->ans_cnt)
        {
            current->ans_cnt=current->next[i]->ans_cnt;
            current->idx=current->next[i]->idx;
        } 

    }
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("inp.txt", "r", stdin);
   freopen("out.txt", "w", stdout);

        int n; cin >> n;
        Node trie;
        vector<string> ss(n);
        for (string &s : ss) {
            cin >> s;
            trie.insert(s);
        }
        dfs(&trie);
        int q;cin>>q;
        while(q--)
        {
            string x;cin>>x;
            auto p=trie.get(x);
            if(p.first==-1)
             cout<<"-1\n";
            else
            {
                cout<<us[p.first]<<" "<<p.second<<'\n';
            }
        }


    return 0;



}
