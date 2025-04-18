class Solution {
public:
/*
Approach: basically laga hai isme recursion aur phir hamne jo vo strring mil rahi hai hame recursion ke baad usey process karne k liye hame kiya hai operation 2 loop wala ek jo ki count nikalega aur dusra wala vo jo rresult wali string me store karega count ko aur character ko 
*/

    string countAndSay(int n) {
        if(n==1) return "1";
        string str = countAndSay(n-1);

        // Processing for the answer starts here
        int m = str.length();
        string result = "";
        for(int i=0;i<m;i++){
            int cnt =1;
            char ch = str[i];
            while(i<m-1 && str[i]==str[i+1]){
                cnt++;
                i++;
                }
        result += to_string(cnt) + ch;
        }
        return result;
    }
};