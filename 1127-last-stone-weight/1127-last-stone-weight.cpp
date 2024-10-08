class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>heap;

        for(int i=0;i<stones.size();i++){
            heap.push(stones[i]);
        }

        while(heap.size()>=2){
            int first_stone=heap.top();
            heap.pop();
            int second_stone=first_stone;
            if(!heap.empty()){
            second_stone=heap.top();
            heap.pop();
            }

            if(first_stone!=second_stone){
                heap.push(first_stone-second_stone);
            }
        }


        if(heap.empty()) return 0;

        return heap.top();
    }
};