#include<bits/stdc++.h>
using namespace std;

class trie{
public:
struct node{
    map<char, node*> children;
    int prefix;
    vector<string> wend;
    node(){
        prefix=0;
    }
};
    node *root;
    trie(){
        root = new node();
    }
    void insert(string s){
        node* nd = root;
        int i=0;
        while(i<s.length()){
            if(nd->children[s[i]]!=NULL){
                nd = nd->children[s[i]];
                nd->prefix++;
                i++;
                continue;
            }
            nd->children[s[i]] = new node();
            nd = nd->children[s[i]];
            nd->prefix++;
            i++;
        }
        nd->wend.push_back(s);
    }

    bool search_word(string s){
        node *nd = root;
        int i=0;
        while(i<s.length()){
            if(nd->children[s[i]]!=NULL){
                nd = nd->children[s[i]];
                i++;
                continue;
            }
            return 0;
        }
        if(nd->wend.size()>0)return 1;
        return 0;
    }


    int count_prefix(string s){
        node *nd = root;
        int i=0;
        while(i<s.length()){
            if(nd->children[s[i]]!=NULL){
                nd = nd->children[s[i]];
                i++;
                continue;
            }
            return 0;
        }
        return nd->prefix;
    }
};





int main(){
    trie tr;
    string s = "hello", t = "hellw";
    tr.insert(s);
    tr.insert(t);
    tr.insert("hell");
    cout<<tr.search_word("hellz")<<endl;
    cout<<tr.count_prefix("hell1")<<endl;
    return 0;
}