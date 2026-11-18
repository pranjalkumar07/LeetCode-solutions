
class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> need(128, 0);
        vector<int> window(128, 0);

        for(char c : t) {
            need[c]++;
        }

        int required = 0;

        for(int i = 0; i < 128; i++) {
            if(need[i] > 0) {
                required++;
            }
        }

        int have = 0;
        int i = 0;

        int minLen = INT_MAX;
        int start = 0;

        for(int j = 0; j < s.size(); j++) {

            char c = s[j];
            window[c]++;

            if(need[c] > 0 && window[c] == need[c]) {
                have++;
            }

            while(have == required) {

                if(j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                char left = s[i];

                if(need[left] > 0 &&
                   window[left] == need[left]) {
                    have--;
                }

                window[left]--;
                i++;
            }
        }

        if(minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};
