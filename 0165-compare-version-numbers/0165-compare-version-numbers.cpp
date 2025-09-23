class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length();
        int m = version2.length();
        int i=0,j=0;
        while(i<n || j<m){
            long long num1 =0,num2=0;
            while(i<version1.length() && version1[i] != '.'){
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            while(j<version2.length() && version2[j] != '.'){
                    num2 = num2*10 + (version2[j] - '0');
                    j++;
                }
        if(num1<num2) return -1;
        if(num1>num2) return 1;
        if(i<n && version1[i] == '.') i++;
        if(j<m && version2[j] == '.') j++;
        }
        return 0;
    }
};