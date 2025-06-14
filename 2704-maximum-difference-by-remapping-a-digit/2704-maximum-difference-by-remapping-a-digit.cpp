class Solution {
public:
    int minMaxDifference(int num) {
        
        string st = to_string(num);
        string maxi = "";
        string mini = "";
        char ele = ' ';
        // sabse pahla non 9 digit nikal liya hamne
        for(int i=0;i<st.size();i++){
            if(st[i] != '9'){
                ele = st[i];
                break;
            }
        }
        for(int i=0;i<st.size();i++){
            if(ele == st[i]) maxi += '9';
            else maxi += st[i];
        }
        
        for(int i=0;i<st.size();i++){
            if(st[0] == st[i]){
                mini += '0';
            }
            else mini += st[i];
        }
        return stoi(maxi) - stoi(mini);
    }
};