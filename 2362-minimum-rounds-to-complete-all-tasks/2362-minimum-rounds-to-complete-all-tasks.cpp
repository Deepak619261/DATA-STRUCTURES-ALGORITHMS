class Solution {
    long long solve(int index,vector<int>arr){
        if(index==arr.size())return 0;

        if(arr[index]<2)return INT_MAX;
        
        long long  first=1e9+1;

        if(arr[index]==2){
           first=1+solve(index+1,arr);
        }
        long long second=1e9+1;
        long long third=1e9+1;

        if(arr[index]==3){
          second=1+solve(index+1,arr);
          arr[index]-=2;
          third=1+solve(index,arr);
          arr[index]+=2;
        }
        else if(arr[index]>3){
          arr[index]-=3;
          second=1+solve(index,arr);
          arr[index]+=3;
          arr[index]-=2;
          third=1+solve(index,arr);
          arr[index]+=2;
        }

        return min(first,min(second,third));
    }
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mpp;
        for(auto it:tasks){
            mpp[it]++;
        }

        vector<int>temp;
        for(auto it:mpp){
            temp.push_back(it.second);
        }

        sort(temp.begin(),temp.end());

        // now the problem reduces to coins ones , we have 2 and 3 coins , see if we can pay the price , unlimited supply of 2-3 coins 
        // return solve(0,temp);
        // it can be solved by greedy approach as well ,
        int rounds=0;
        for(auto it:temp){
            if(it==1)return -1;
            else{
                rounds+=(it+2)/3;
            }
            
        } 

        return rounds;

        //thought process start taking number from 1 to 9 -> 1 -> -1 
        //  2-> 1(2)
        //  3 -> 1(3)
        // 4 -> 2(2+2)
        // 5-> 2(3+2)
        //  6-> 2(3+3)
        // 7 -> 3(3+2+2)
        //  three case -> if divisible -> add direct quotient 
        //  if remainder 1 -> remove one 3 round , and add two 2's rounds
        // if remainder -> 2 -> then simple take ans after division and add 1 more round 

        // if we observe above the formula starts to hint at ceil(x/3)

        
    }
};