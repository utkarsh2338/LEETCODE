// class Solution {
// public:
//     string makeFancyString(string s) {
//         int count = 1;  // Counter for consecutive characters
//         for (int i = 1; i < s.length(); ) {
//             if (s[i] == s[i - 1]) {
//                 count++;  // Increment count for consecutive characters
//             } else {
//                 count = 1;  // Reset count if character changes
//             }
            
//             if (count >= 3) {
//                 s.erase(i, 1);  // Erase the character at position i
//             } else {
//                 i++;  // Move to the next character only if no deletion occurs
//             }
//         }
//         return s;
//     }
// };


class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        ans.push_back(s[0]);
        int n = s.size(),cnt = 1;
        for(int i=1;i<n;i++){
            if(s[i] == ans.back()){
                cnt++;
                if(cnt < 3)ans.push_back(s[i]);
            }
            else{
                cnt = 1;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};