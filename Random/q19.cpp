#include<bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* curr = head;
        int i=0;
        while(curr!=nullptr){
            curr=curr->next;
            i++;
        }
        if(n>i)
            return head;

        curr=nullptr;
        ListNode* next = head;
        n=i-n+1;
        i=1;

        while(next!=nullptr and i<n){
            curr=next;
            next=next->next;
            i++;
        }
        // cout<<curr->val<<" "<<next->val<<endl;
        if(curr){
            if(!next){
                return head;
            }
            curr->next = next->next;
            return head;
        }
        return head->next;


    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    

    int f;
    cin>>f;
    
    ListNode* a = new ListNode(f);
    ListNode* b = a;
    
    for (int i = 1; i < n; i++){
        int d;
        cin>>d;
        
        b->next=new ListNode(d);
        b=b->next;
        
    }

    int del;
    cin>>del;
    
    Solution sol;
    a = sol.removeNthFromEnd(a,del);
    while(a!=nullptr){
        cout<<a->val<<" ";
        a=a->next;
    
    }
    cout<<" "<<endl;
    return 0;

}


