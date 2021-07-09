#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* prev = nullptr;
        ListNode* curr = head;

        int n=0;
        while(curr!=nullptr){
            curr=curr->next;
            n+=1;
        }

        curr=head;
        int j=0;
        while(j<n/k){
            ListNode* t = curr;
            ListNode* next = curr->next;
            int i=1;
            while(i<k){
                ListNode* temp = next->next;
                next->next = curr;
                curr= next;
                next = temp;
                i+=1;
            }
            if(prev)
                prev->next = curr;
            else head = curr;
            curr=next;
            t->next = curr;
            prev=t;
            j+=1;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}