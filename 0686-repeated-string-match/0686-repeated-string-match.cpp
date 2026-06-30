class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        int cnt = 1;
        string source = a;

        while(source.size() < b.size()) {
            source += a;
            cnt++;
        }
        if(rabinKarp(source, b) != -1)
            return cnt;

        source += a;
        if(rabinKarp(source, b) != -1)
            return cnt + 1;

        return -1;
    }

private:
    int rabinKarp(string &text, string &pattern) {

        int n = text.size();
        int m = pattern.size();

        if(m > n)
            return -1;

        const long long base = 31;
        const long long mod = 1e9 + 7;

        long long highestPower = 1;

        for(int i = 0; i < m - 1; i++)
            highestPower = (highestPower * base) % mod;

        long long patternHash = 0;
        long long windowHash = 0;

        for(int i = 0; i < m; i++) {
            patternHash = (patternHash * base + pattern[i]) % mod;
            windowHash = (windowHash * base + text[i]) % mod;
        }

        for(int i = 0; i <= n - m; i++) {

            if(patternHash == windowHash) {

                bool match = true;

                for(int j = 0; j < m; j++) {
                    if(text[i + j] != pattern[j]) {
                        match = false;
                        break;
                    }
                }

                if(match)
                    return i;
            }

            if(i < n - m) {

                windowHash = (windowHash -
                             (text[i] * highestPower) % mod + mod) % mod;

                windowHash = (windowHash * base + text[i + m]) % mod;
            }
        }

        return -1;
    }
};