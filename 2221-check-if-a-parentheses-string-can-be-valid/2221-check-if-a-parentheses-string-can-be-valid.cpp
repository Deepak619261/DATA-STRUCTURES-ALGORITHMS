class Solution {
public:
    bool canBeValid(string s, string locked) {
        // intution of the problem 
        //  brute force that we can try every combination by recursion that will take 2^n and given 10^5 constraints it can be only solved in O(n) time complexity 
        //  next we can use stack for the order and parenthesis thing but handling locked and unlocked cases will add the complexity Using a Stack Utilize a stack to track opening parentheses and ensure proper matching.
        /*
Adaptation for Locked Characters:
Locked '(' or ')': Handle normally.
Unlocked Characters: Treat them as either '(' or ')', introducing flexibility.
Challenges:

Deciding when to treat an unlocked character as '(' or ')' dynamically is complex.
Managing multiple possibilities increases complexity, potentially leading to inefficiency.*/ 


// the effiecient appraoch remains using counters so what we can do that we can check for every locked ')' if these can be balanced and the same thing can be done from the back , traversing in the reverse direction , which was the last submission 


// now comes the efficient aprraoch 

// invalid case 
if(s.size()%2!=0)return false;

if(s.back()=='(' && locked.back()=='1' || s[0]==')' && locked[0]=='1')return false;

int maxop=0;
int minop =0;

for(int i=0;i<s.size();i++){
    if(locked[i]=='1'){
        if(s[i]=='('){
            maxop++;
            minop++;
        }
        else{
            maxop--;
            minop--;
        }
    }
    else{
        minop--; // considering the unlocked character can be ')' for seeing that if there remains a open bracket at the end of the traverrsal 
        maxop++;
    }

    minop=max(0,minop);

    if(maxop<0)return false;
}



return minop==0;
    }
};