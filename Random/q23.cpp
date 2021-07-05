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

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* ansN = ans;
        while(l1 != nullptr and l2 != nullptr){
            if(l1->val>=l2->val){
                while(l2!=nullptr and l1->val>=l2->val){
                    ansN->next = l2;
                    ansN = ansN->next;
                    l2 = l2->next;
                }
            }
            if(l2!= nullptr and l2->val>=l1->val){
                while(l1!=nullptr and l2->val>=l1->val){
                    ansN->next = l1;
                    ansN = ansN->next;
                    l1 = l1->next;
                }
            }
        }

        if(l1!=nullptr){
            while(l1!=nullptr){
                ansN->next = l1;
                ansN = ansN->next;
                l1 = l1->next;
            }
        }

        if(l2!=nullptr){
            while(l2!=nullptr){
                ansN->next = l2;
                ansN = ansN->next;
                l2 = l2->next;
            }
        }

        return ans->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        //O(nk)

        if(lists.size()==0){
            return nullptr;
        }

        else if(lists.size()==1){
            return lists[0];
        }

        ListNode* ans = mergeTwoLists(lists[0],lists[1]);
        for (int i = 2; i < lists.size(); i++){
        
            ans = mergeTwoLists(ans,lists[i]);
        }
        return ans;
    }

    ListNode* mergeKLists2(vector<ListNode*>& lists) {

        //O(nlogk)

        if(lists.size()==0){
            return nullptr;
        }

        else if(lists.size()==1){
            return lists[0];
        }

        ListNode* prev = mergeTwoLists(lists[0],lists[1]);
        for (int i = 2; i < lists.size(); i+=2){
            if(i==lists.size()-1){
                prev = mergeTwoLists(prev,lists[i]);
                continue;
            }
            prev = mergeTwoLists(prev,mergeTwoLists(lists[i],lists[i+1]));
        }
        return prev;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}