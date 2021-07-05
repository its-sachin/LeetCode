#include<bits/stdc++.h>

using namespace std;

#define inf 1e18
#define mod 1000000007
#define pb push_back

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    void swap(ListNode* a){
        if(a->next){
            ListNode* curr = a->next;
            a->next = a->next->next;
            curr->next = a;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr or head->next == nullptr)
            return head;
        
        ListNode* curr = head->next;
        swap(head);
        head = curr;
        
        if(head->next->next){

            ListNode* prev = head->next;
            curr = prev->next;
            ListNode* next = curr->next;

            while(next!=nullptr){
                prev->next = next;
                prev = curr;
                swap(curr);
                curr = curr->next;
                if(curr)
                    next = curr->next;
                else
                    next = curr
            }
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}