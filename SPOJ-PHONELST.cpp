// Phone List
// https://vjudge.net/problem/SPOJ-PHONELST
// Solution with counting the strings of this prefix.


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node{

bool isword=false;
int cnt=0;
Node* next[26]{};

void insert (string &s)
{
    Node* current=this;
    for(auto c:s)
    {
        int i=c-'0';
        if(current->next[i]==nullptr)
            current->next[i]=new Node;
        current=current->next[i];
         ++current->cnt;
    }
    current->isword=true;
}


int count(string &s)
{
    Node* current=this;
    for(auto c:s)
    {
        int i=c-'0';
        if(current->next[i]==nullptr)
            return 0;
        current=current->next[i];
    }
    return  current->cnt;
}


};


int main()
{
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        Node trie;
        vector<string> ss(n);
        for (string &s : ss) {
            cin >> s;
            trie.insert(s);
        }
        bool is_consistent = true;
        for (auto s : ss)
            is_consistent and_eq trie.count(s) == 1;
        cout << (is_consistent ? "YES\n" : "NO\n");
    }
    return 0;
   
  

}
