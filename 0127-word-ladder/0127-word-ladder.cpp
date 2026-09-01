class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // Store all words for O(1) lookup
        unordered_set<string> st(wordList.begin(), wordList.end());

        // If endWord is not present, no transformation is possible
        if (st.find(endWord) == st.end()) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string word = q.front();
                q.pop();

                // Try changing every character
                for (int i = 0; i < word.size(); i++) {
                    
                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        
                        word[i] = ch;

                        // If this transformed word exists
                        if (st.find(word) != st.end()) {
                            
                            // Reached endWord
                            if (word == endWord) {
                                return level + 1;
                            }

                            q.push(word);

                            // Remove so that we don't visit it again
                            st.erase(word);
                        }
                    }

                    word[i] = original;
                }
            }

            level++;
        }

        return 0;
    }
};