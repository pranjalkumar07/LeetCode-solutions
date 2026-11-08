
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {

            // Find vowel from left
            while (i < j && 
                   s[i] != 'a' && s[i] != 'e' && 
                   s[i] != 'i' && s[i] != 'o' && 
                   s[i] != 'u' && s[i] != 'A' && 
                   s[i] != 'E' && s[i] != 'I' && 
                   s[i] != 'O' && s[i] != 'U') {
                i++;
            }

            // Find vowel from right
            while (i < j && 
                   s[j] != 'a' && s[j] != 'e' && 
                   s[j] != 'i' && s[j] != 'o' && 
                   s[j] != 'u' && s[j] != 'A' && 
                   s[j] != 'E' && s[j] != 'I' && 
                   s[j] != 'O' && s[j] != 'U') {
                j--;
            }

            // Swap vowels
            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};
