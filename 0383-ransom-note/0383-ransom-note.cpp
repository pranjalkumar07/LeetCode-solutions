
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> mp1, mp2;

        for(char ch : ransomNote) {
            mp1[ch]++;
        }

        for(char ch : magazine) {
            mp2[ch]++;
        }

        for(auto it : mp1) {

            if(mp2[it.first] < it.second) {
                return false;
            }
        }

        return true;
    }
};
