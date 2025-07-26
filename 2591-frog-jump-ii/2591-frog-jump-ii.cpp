class Solution {

    int simulate(vector<int>& stones, int i) {
        if (i >= stones.size() - 1) return 0;

        int jump = stones[i + 2] - stones[i];
        int rest = simulate(stones, i + 2);

        return max(jump, rest);
    }

public:
    int maxJump(vector<int>& stones) {
    int n =stones.size();

    // the realization here is when you will dry run you will realize that the cost is caused by the very last stone to the stone at index zero 
    // so what is happening we are trying to put the two stones together whoese diff is less  
    // if frog skips more than one stone then he has to covver the cost in one single jump in both side so optimal is to just skip one stone fro return 
    //  its the zigzag pattern where we use this pattern to keep the maximum diff between adjcent element is minimum as possilbe for that we pick small-> larget-> second sammlest -> second largest in this way 
        
    int maxCost = 0;
    if(n==2)return stones[1]-stones[0];

    for (int i = 2; i < n; ++i) {
        maxCost = max(maxCost, stones[i] - stones[i - 2]);
    }

    return maxCost;


    }
};