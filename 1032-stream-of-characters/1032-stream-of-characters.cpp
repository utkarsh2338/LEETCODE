class StreamChecker {
public:
    struct Node {
        Node* next[26] = {};
        bool end = false;
    };

    Node* root;
    string stream;
    int maxLen = 0;

    StreamChecker(vector<string>& words) {
        root = new Node();
        for (string &w : words) {
            maxLen = max(maxLen, (int)w.size());
            Node* cur = root;
            for (int i = w.size() - 1; i >= 0; i--) {
                int c = w[i] - 'a';
                if (!cur->next[c]) cur->next[c] = new Node();
                cur = cur->next[c];
            }
            cur->end = true;
        }
    }
    
    bool query(char letter) {
        stream.push_back(letter);
        Node* cur = root;
        for (int i = stream.size() - 1, k = 0; i >= 0 && k < maxLen; i--, k++) {
            int c = stream[i] - 'a';
            if (!cur->next[c]) return false;
            cur = cur->next[c];
            if (cur->end) return true;
        }
        return false;
    }
};
