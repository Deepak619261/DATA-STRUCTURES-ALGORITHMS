class Solution {
public:
    vector<int> minOperations(string boxes) {
        // store the indexes of the places where 1 occures
        vector<int>temp;

        for(int i=0;i<boxes.size();i++){
            if(boxes[i]=='1'){
                temp.push_back(i);
            }
        }

        int n=boxes.size();


        vector<int>ans(n,0);

        //  for eg :- index array should be like eg1-> "110"-> [0,1] and "001011"->[2,4,5]

        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=0;j<temp.size();j++){
                curr+=abs(i-temp[j]);
            }
            ans[i]=curr;
        }




        return ans;
    }
};