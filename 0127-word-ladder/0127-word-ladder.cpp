class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordListSet(wordList.begin(),wordList.end());
        unordered_set<string>visited;

        queue<string>q;
        q.push(beginWord);
        visited.insert(beginWord);
        int level =1;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string curr = q.front();
                q.pop();
                if(curr == endWord) return level;

                for(char ch='a';ch<='z';ch++){
                    for(int i=0;i<curr.length();i++){
                        string temp = curr;
                        temp[i] = ch;

                        if((visited.find(temp) == visited.end()) &&(wordListSet.find(temp) != wordListSet.end())){
                            visited.insert(temp);
                            q.push(temp);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};