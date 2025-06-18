class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        bool flag = false;
        if(n == 1) return "";
        for(int i=0;i<n/2;i++){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                flag = true;
                break;
            }
        }
        if(flag == false && n > 1){
            palindrome[n-1] = 'b';
        }
        return palindrome;
    }
};