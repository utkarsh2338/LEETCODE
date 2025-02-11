class Solution {
public:
    string removeOccurrences(string s, string part) {
        // brute force part ko isme dhundhte chalo aur jaha bhi mil raha hhai waha par erase function lagao aur fir se find karo mile toh erase karo
        int n = s.length();
        while(true){
            int idx = s.find(part);
            
            if(idx == string:: npos){// agr nahi milta jo mai dhundh raha toh fir mai break kar jaunga
                break;
            }
            s.erase(idx,part.length());//kis index se start karenge aur kitna hatayenge vo dena hota hai
        }
        return s;
    }
};