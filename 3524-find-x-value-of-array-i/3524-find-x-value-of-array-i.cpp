class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);   // final answer
        vector<long long> cnt(k, 0);      // subarrays ending at previous index

        for (int num : nums) {
            vector<long long> newCnt(k, 0);

            // extend every previous subarray by including num
            for (int r = 0; r < k; r++) {
                int newRem = (r * (num % k)) % k;
                newCnt[newRem] += cnt[r];
            }

            // start a new subarray with only num
            newCnt[num % k]++;

            // add this round's counts to the answer
            for (int r = 0; r < k; r++) {
                result[r] += newCnt[r];
            }

            cnt = newCnt;
        }

        return result;
    }
};