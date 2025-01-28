class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        // start thinking like this -> 
        /*
        see the very first conditon it says that we can split the array into any number of contiguous subarrays , and the cost will be fixed that is k 
        second condition says that we can subtract/add the element to the current element in order to make it equal to the element of brr , here take the example of  arr-> 4,9 && arr-> 8,3
        // simple calculations will be 4+4-> 8 and 9-6->6 -> 14 
        but 4->3 -> 1 and 9->8 -> 1
        and ans -> two 
        so we want those element which have close value to the current element , how can we do it , take a shortest element of the arr and look for the shortest element of brr , because anything bigger than that cause the more difference between them so simple intution comes of sorting both the arrays 

        // here comes the edge case there may be possibility that without sorting , we can get the optimal cost by applying the operations to the current arrangement as well 
        // so we have to calculate the cost in two condition first without sorting and second with sort and return the minimum of the both 
        */

        long long answer=LLONG_MAX;

        long long res=0;

        for(int i=0;i<arr.size();i++){
            res+=abs(arr[i]-brr[i]);
        }

        answer=min(answer,res);

        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());

        res=0;
        for(int i=0;i<arr.size();i++){
           res+=abs(arr[i]-brr[i]);
        }

       answer=min(answer,res+k);

       return answer;

        
    }
};