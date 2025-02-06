class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry =0;
        if(digits.back()<9){
            digits[digits.size()-1]=digits.back()+1;
            return digits;
        }


        digits.back()=0;
        carry=1;

        for(int i=digits.size()-2;i>=0;i--){
            if(digits[i]==9){
                digits[i]=0;
                carry=1;
            }
            else{
                digits[i]+=carry;
                carry=0;
                break;
            }
        }

        if(carry){
            reverse(digits.begin(),digits.end());
            digits.push_back(1);
            reverse(digits.begin(),digits.end());
        }

        return digits;
    }
};