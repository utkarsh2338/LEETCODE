class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mapT, windowMap;
        int required = t.size(); 
        int formed = 0;           
        int left = 0, right = 0; 
        int minLength = INT_MAX; 
        int start = 0;            
        
        for (char c : t) {
            mapT[c]++;
        }

        while (right < s.size()) {
           
            windowMap[s[right]]++;

         
            if (mapT.find(s[right]) != mapT.end() && windowMap[s[right]] <= mapT[s[right]]) {
                formed++;
            }

            while (left <= right && formed == required) {
               
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                
                windowMap[s[left]]--;
                if (mapT.find(s[left]) != mapT.end() && windowMap[s[left]] < mapT[s[left]]) {
                    formed--;
                }
                left++;
            }

            right++;
        }

        if (minLength == INT_MAX) {
            return "";
        }
        return s.substr(start, minLength);
    }
};
