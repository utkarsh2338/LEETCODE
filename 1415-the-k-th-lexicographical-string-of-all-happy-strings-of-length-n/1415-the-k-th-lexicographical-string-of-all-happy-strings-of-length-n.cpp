class Solution {
string ans;
int N,K;
private:
    bool f(bool f1,bool f2,bool f3,string str){
        if(str.length()==N){
            K--;
            if(K==0){
                ans=str;
                return true;
            }
            return false;
        }
        if(f1&&f(0,1,1,str+"a"))return true;
        if(f2&&f(1,0,1,str+"b"))return true;
        if(f3&&f(1,1,0,str+"c"))return true;
        return false;
    }
public:
    string getHappyString(int n, int k) {
        N=n,K=k;
        ans="";
        f(1,1,1,"");
        return ans;
    }
};