#include<bits/stdc++.h>

using namespace std;

// typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Node{


public:
    int val;
    string s;
};

class Solution {
public:

    vector<Node> rec(int k, int n, vector<Node> v){
        vector<Node> a;

        for(int i=0; i<v.size(); i++){
            if(v[i].val>0){
                Node n;
                n.val=v[i].val;
                n.s=v[i].s;
                n.s.push_back(')');
                n.val -=1;
                a.push_back(n);
            }
            if((v[i].val + v[i].s.size())<2*n){
                Node n = v[i];
                n.val=v[i].val;
                n.s=v[i].s;
                n.s.push_back('(');
                n.val +=1;
                a.push_back(n);
            }
        }
        return a;

    }
    vector<string> generateParenthesis(int n) {
        vector<Node> v;
        Node no;
        no.val=1;
        no.s="(";
        v.push_back(no);

        for(int i=1; i<2*n;i++){
            v = rec(i,n,v);
        }

        vector<string> ans;
        for (int i=0; i<v.size();i++){
            ans.push_back(v[i].s);
        }
        
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    Solution O;
    vector<string> v = O.generateParenthesis(n);
    for (int i = 0; i < v.size(); i++){
        
        cout<<v[i]<<" ";
        
    }
    cout<<""<<endl;
    return 0;
}