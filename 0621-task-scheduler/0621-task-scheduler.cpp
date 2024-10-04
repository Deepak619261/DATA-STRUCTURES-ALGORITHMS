class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int arr[26]={0};

        for(char c:tasks){
            arr[c-'A']++;
        }

        //  sort the arr
        sort(begin(arr),end(arr));

        //  take the most frequent 
        int chunks=arr[25]-1;

        int idle_slots=chunks*n;

        for(int i=24;i>=0;i--){
            idle_slots-=min(chunks,arr[i]);
        }


        if(idle_slots>=0){
            return tasks.size()+idle_slots;
        }

        return tasks.size();

    }
};