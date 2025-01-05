class Solution {
public:
    long long calculateScore(string s) {
        // saw the solution from the discuss section as i was only able to derive the approach where unique elements are there , but for keeping take care of the duplicate enteries , i have to maintain the list of the indexes where mirro image is showed 
        // the thing is you have to first solve on the paper and after thinking about every possible case that may occuree then start writing 
        long long answer=0;

        map<int,vector<int>>mpp;

        for(int i=0;i<s.size();i++){
            int curr=s[i]-'a';
            if(mpp.find(25-curr)!=mpp.end() && mpp[25-curr].size()>0){
                answer+=(i-mpp[25-curr].back());
                mpp[25-curr].pop_back();
            }
            else{
                mpp[curr].push_back(i);
            }
        }

        return answer;
    }
};