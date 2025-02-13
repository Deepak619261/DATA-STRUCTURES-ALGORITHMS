class Solution {
public:
    int halveArray(vector<int>& nums) {
        // it is based on the similar approach,as the previous question , 
        priority_queue<double>pq;
        double sum=0;
        int count=0;
        for(auto it:nums){
            pq.push(it);
            sum+=it;
        }

        double target=sum/2;

        cout<<target;
        while(sum>target){
              double ele=pq.top();
              pq.pop();
              sum-=(ele/2);
              pq.push(ele/2);
              count++;
              cout<<"iteration"<<count<<endl;

            //   for(auto it:pq){
            //     cout<<it<<" ";
            //   }
            //   cout<<endl;
        }


        return count;




    }
};