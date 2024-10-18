class Solution {
    bool solve(string str, int left, int right){
        if(left==right){
            return str[left]=='t';
        }

        if(str[left]=='!'){
            return !solve(str,left+2,right-1);
        }

        if(str[left]=='&'){
            int i=left+2;
            bool result=true;
            int start=i;
            int openparenthesis=0;

            while(i<=right){
                 if(str[i]=='(') openparenthesis++;
                 if(str[i]==')') openparenthesis--;

                 if(str[i]==',' && openparenthesis==0){
                    result &=solve(str,start,i-1);
                    start=i+1;
                 }

                 i++;
            }
            result &= solve(str, start, right - 1);
            return result;
        }

        //  if we found the sign as |
        if (str[left] == '|') {
        int i = left + 2; // Start after '|('
        bool result = false;
        int start = i;
        int openParens = 0;

        while (i <= right) {
            if (str[i] == '(') openParens++;
            if (str[i] == ')') openParens--;
            
            // If we encounter a comma with no open parentheses, it means a sub-expression has ended
            if (str[i] == ',' && openParens == 0) {
                result |= solve(str, start, i - 1); // OR with the result of the sub-expression
                start = i + 1;
            }
            i++;
        }
        // Evaluate the last part of the OR expression
        result |= solve(str, start, right - 1);
        return result;
    }

    return false;
    }
public:
    bool parseBoolExpr(string expression) {
        return solve(expression ,0, expression.size()-1);
    }
};