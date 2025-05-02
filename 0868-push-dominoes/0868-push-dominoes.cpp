class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L' + dominoes + 'R';
        string ans;
        int prev = 0;
        for(int curr = 1; curr<dominoes.length();curr++){
            if(dominoes[curr] == '.'){
                continue;
            }
            int span = curr - prev - 1;
            if(prev>0){
                ans += dominoes[prev];
            }
            if(dominoes[prev] == dominoes[curr]){
                ans += string(span,dominoes[prev]);
            }
            else if(dominoes[prev] == 'L' && dominoes[curr] == 'R'){
                ans += string(span,'.');
            }
            else{
                ans += string(span/2,'R') + string(span%2,'.') + string(span/2,'L');
            }
            prev = curr;
        }   
        return ans;
    }
};