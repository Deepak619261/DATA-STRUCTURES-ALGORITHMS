class Solution {
    bool isvalid(string str){
        if(str=="")return false;
        for(auto it:str){
            if(!(it>='a' && it<='z') && !(it>='A' && it<='Z') && !(it>='0' && it<='9') && it!='_'){
               return false;
            }
        }
        return true;
    }

    struct CustomSort {
    unordered_map<string, int> category_order;

    CustomSort() {
        category_order["electronics"] = 0;
        category_order["grocery"]     = 1;
        category_order["pharmacy"]    = 2;
        category_order["restaurant"]  = 3;
    }

    bool operator()(const pair<string, string>& a, const pair<string, string>& b) const {
        if (category_order.at(a.second) != category_order.at(b.second))
            return category_order.at(a.second) < category_order.at(b.second);
        return a.first < b.first;
    }
};
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        
        vector<pair<string,string>>temp;
        for(int i=0;i<code.size();i++){
            if(isvalid(code[i]) && (businessLine[i]=="electronics" || businessLine[i]=="grocery" || businessLine[i]=="pharmacy"|| businessLine[i]=="restaurant") && isActive[i]){
               temp.push_back({code[i],businessLine[i]});
            }
        }

        sort(temp.begin(), temp.end(), CustomSort());
        vector<string>vec;
        for(auto it:temp){
            cout<<it.first<<" ";
            vec.push_back(it.first);
        }
        return vec;
    }
};