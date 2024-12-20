class Solution {
public:
    void solve(vector<string>&  ans,int index,string output,string digits,string mapping[]){
        //base case
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        //Whenever i subtract '0' from any string it gets converted into integer
        int number = digits[index] -'0';
        string value = mapping[number];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(ans,index+1,output,digits,mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string output = "";
        int index = 0;
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string mapping[10] ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(ans,index,output,digits,mapping);
        return ans;
    }
};