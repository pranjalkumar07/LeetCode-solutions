class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int low=0;
        int maxlen=0;

        for(int high=0;high<s.size();high++){
            freq[s[high]-'A']++;
            int len=high-low+1;

            int maxcnt = *max_element(freq.begin(),freq.end());
            int diff = len-maxcnt;

            while(diff>k){
                freq[s[low]-'A']--;
                low++;
                len = high - low + 1;
                maxcnt = *max_element(freq.begin(),freq.end());
                diff = len-maxcnt;
            }
            maxlen=max(maxlen,len);
        }
        return maxlen;
    }
};