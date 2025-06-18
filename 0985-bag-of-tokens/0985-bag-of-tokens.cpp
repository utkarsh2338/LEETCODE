class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(),tokens.end());

        int n = tokens.size();
        int i =0,j=n-1;
        int score = 0,maxScore = 0;

        while(i<=j){
            if(power >= tokens[i]){
                power -= tokens[i++];
                score++;
                maxScore = max(score,maxScore);
            }
            else if(score>=1){
                power += tokens[j--];
                score--;
                 
            }
            else break;

        }
        return maxScore;
    }
};