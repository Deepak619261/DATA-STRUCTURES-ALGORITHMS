/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;

        vector<int>nums;

        while(temp){
             nums.push_back(temp->val);
             temp=temp->next;
        }

        vector<int>rev=nums;
        reverse(rev.begin(),rev.end());
        return nums==rev;
    }
};