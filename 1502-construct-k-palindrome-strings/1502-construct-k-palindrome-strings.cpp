class Solution {
public:
    bool canConstruct(string s, int k) {
        // intution i am getting is that if we found any character with odd frequency than its representing the obstacle in making palindrome which can be handled by putting it in the centre so for having a palindrome it is neccessary that for each palindrome we can have only one odd character so we just have to check if the total number of character which have odd freuquency is less than or equal to k , 

        // if(s.size()%k==0)return true;

        if(s.size()<k)return false;

        
        // if(s.size()%k==0)return false;

        vector<int>arr(26,0);
        for(auto it:s){
            arr[it-'a']++;
        }
        
        int oddfreq=0;
        int evenfreq=0;
        int count=0;

        for(auto it:arr){
           if(it!=0){
            if(it%2==0){
                evenfreq++;
            }
            else{
                oddfreq++;
            }
           }
        }
       
       cout<<evenfreq<<oddfreq<<endl;
        

        return oddfreq<=k;
    }
};