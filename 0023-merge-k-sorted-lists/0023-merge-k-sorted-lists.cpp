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
    void pushtovector(vector<vector<int>>&nums,ListNode* head,int row){
       ListNode* temp=head;
       while(temp!=NULL){
            nums[row].push_back(temp->val);
            temp=temp->next;
       }
    }

    
     vector<int> mergeKArrays(vector<vector<int>> arr)
    {
        //code here
        int n=arr.size();
        vector<int>ans;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        for(int i=0;i<arr.size();i++){
            //  we will push the data like {element,row, col}
            if(!arr[i].empty()){
            pq.push({arr[i][0],{i,0}});
            }
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row<n && col<arr[row].size()-1){
                pq.push({arr[row][col+1],{row,col+1}});
            }
        }
        
        return ans;
        
        
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //  one of the brute force way is to convert all this into vector vector of array 
        int n=lists.size();
        if(n==0) return NULL;
       
        vector<vector<int>>nums(n);
        for(int i=0;i<lists.size();i++){
            pushtovector(nums,lists[i],i);
        }

        vector<int>ans=mergeKArrays(nums);
        if(ans.size()==0) return NULL;

     
        // if(nums.size()==0) return NULL;
        ListNode  *head=new ListNode(ans[0]);
        ListNode  *temp=head;

        for(int i=1;i<ans.size();i++){
            ListNode *store=new ListNode(ans[i]);
            temp->next=store;
            temp=store;
        }
        temp->next=NULL;
        return head;

    }
};