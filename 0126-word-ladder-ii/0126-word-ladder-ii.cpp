class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);

        unordered_map<string, int> dist;
        dist[beginWord] = 0;

        while (!q.empty()) {

            string curr = q.front();
            q.pop();

            int level = dist[curr];

            for (int i = 0; i < curr.size(); i++) {

                string next = curr;
                char original = next[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    next[i] = ch;

                    if (!st.count(next))
                        continue;

                    // First visit
                    if (!dist.count(next)) {

                        dist[next] = level + 1;
                        q.push(next);

                        parent[next].push_back(curr);
                    }

                    // Another shortest path
                    else if (dist[next] == level + 1) {

                        parent[next].push_back(curr);
                    }
                }
            }
        }

        if (!dist.count(endWord))
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};