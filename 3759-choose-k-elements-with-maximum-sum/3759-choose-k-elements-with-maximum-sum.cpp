class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
                                 int k) {
        
        vector<int>temp=nums1;
        int n = nums1.size();
        vector<long long> ans(n, 0);

        // Map each number in nums1 to its original index.
        map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums1[i]].push_back(i);
        }

        // Use stable sort (instead of Array.Sort) on nums1.
        stable_sort(nums1.begin(), nums1.end());

        // Create the 'arr' array of size n.
        // For each sorted element in nums1, set arr[i] = nums2[mpp[nums1[i]]].
        vector<long long> arr(n, 0);
        int i = 0;
        // int cnt = 0;
      for(auto it:mpp){
            for(auto it2:it.second){
                arr[i++]=nums2[it2];
            }  
         }

        // Create the preAns array.
        vector<long long> preAns(n, 0);
        preAns[0] = 0;

        // Use a min-heap (priority_queue with greater comparator) for k-max
        // calculation.
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long sum = arr[0];
        pq.push(sum);

        for (int i = 1; i < n; i++) {
            // If the current nums1 value is equal to the previous one, skip.
            // if (nums1[i] == nums1[i - 1]) {
            //     preAns[i]=preAns[i-1];
            //     continue;
            // }
            // If the heap has more than k elements, remove the smallest.
            if (pq.size() > (size_t)k) {
                sum -= pq.top();
                pq.pop();
            }

            if (nums1[i] == nums1[i - 1]) {
                preAns[i] = preAns[i - 1];
            } else {
                preAns[i] = sum;
            }
            sum += arr[i];
            pq.push(arr[i]);
        }

        // Restore original order: assign preAns[i] to ans at the index given by
        // mpp.
        // i = 0;
        // cnt = 0;

        // while (i < n && cnt < n) {
        //     for (auto it : mpp[nums1[i]]) {
        //         // arr[cnt++] = nums2[it];
        //         ans[it]=preAns[cnt++];
        //     }
        //     i++;
        // }
        // int cnt=0;



        // for(auto it:mpp){
        //     cout<<it.first<<"-";
        //     for(auto it2:it.second){
        //         cout<<it2<<",";
        //     }
        //     cout<<endl;
        // }

        // int cnt=0;
       

        // int i = 0;
        int cnt=0;
        for (auto& it : mpp) {
            for (auto it2 : it.second) {
                ans[it2] = preAns[cnt++];
            }
        }
       

        return ans;

        // return preAns;
        // return arr;
    }
};