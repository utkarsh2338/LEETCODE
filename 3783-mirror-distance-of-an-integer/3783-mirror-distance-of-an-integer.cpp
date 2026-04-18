class Solution {
public:
    int mirrorDistance(int n) {
        string str = to_string(n);
        int len = str.length();
        int i = 0, j = len-1;
        while(i<j){
            swap(str[i],str[j]);
            i++;
            j--;
        }
        int x = stoi(str);
        int ans = abs(x-n);
        return ans;
    }
};