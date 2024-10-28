class Solution {
    int rabinkarp(string pattern , string text){
            int d=256;
            int q=101;
            
            int m=pattern.size();
            int n=text.size();
            
            int p=0;
            int t=0;
            
            int h=1;
            
            //  we have to calculate base^m-1
            
            for(int i=0;i<m-1;i++){
                h=(h*d)%q;
            }
            
            //  now calculate the first hash value from the pattern and 
            //  text 
            
            for(int i=0;i<m;i++){
                p=(p*d+pattern[i])%q;
                t=(t*d+text[i])%q;
            }
            
            
            for(int i=0;i<=n-m;i++){
                
                if(p==t){
                    //  if hash values are matching we will actually compre
                    // the two substrings 
                    int j=0;
                    
                    for(j=0;j<m;j++){
                        if(text[i+j]!=pattern[j]){
                            break;
                        }
                    }
                    
                    if(j==m){
                        return i;
                    }
                }
                
                
                //  roll out the hash function to the next set of values 
                if(i<n-m){
                    t=((t-text[i]*h)*d + text[i+m])%q;
                    
                    if(t<0){
                        t=t+q;
                    }
                }
                
            }
            
            
            return -1;
            
    }
public:
    int repeatedStringMatch(string a, string b) {
        // if(a.size()>b.size() && b!="") return -1;


        if(a==b) return 1;

        string str=a;

        int ans=1;

        while(str.size()<b.size()){
              ans++;
              str+=a;
        }

        if(str==b) return ans;

        if(rabinkarp(b,str)!=-1) return ans;
        if(rabinkarp(b,str+a)!=-1) return ans+1;


        return -1;
        
    }
};