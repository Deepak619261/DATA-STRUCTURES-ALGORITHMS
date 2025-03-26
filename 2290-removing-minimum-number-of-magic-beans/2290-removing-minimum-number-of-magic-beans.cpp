class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long ans=0;
        // solution from deepseek the thought process 
        // we have beans , from examples we are clear that we can make some bags empty , but non empty bags should be eqaul ->
        // we want since for bags we are emtpying we are removing all the beans we want them to minimum -> will increase are removal of beans 
        // but for non empty bags we want a comman target such that its difference with all other bags should be as minimum as possible 
        // so lets say we want x bags to be empty and wanted n-x bags to have equal amount of beans -
        // we can sort the array ->lets say for we don't want any bean bag to empty then we take that 

        sort(beans.begin(),beans.end());
        int n=beans.size();
        long long maxi=INT_MIN;
        int ind=-1;

        for(int i=0;i<beans.size();i++){
            ans+=beans[i];
            long long curr=(long long)beans[i]*(long long)(n-i);
            if(curr>maxi){
               ind=i;
               maxi=curr;
            }
        }

        // reaching till this logic beans[i]*(n-1-1)>maxi -> is that suppose we have x bags to remove all the beans x*SIgma(beans(i))+ySIgma(abs(target-beans(i)))=> expand it 
        // => x*sigma(beans(i))+y*sigma*(beans(i))-y*target
        // total sum of beans -y*target 
        // above is the required ans we want to minimize it -> so we want maximum(y*target)-> target can be any value amont the beans given -> if we sort the array we are keeping the record of this maximization ->beans[i]*(n-1-1)>maxi


        return ans-maxi;

        

    }
};