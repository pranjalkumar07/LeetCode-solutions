class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n =nums.size();
        int l=0;
        int r=0;
        int maxlen=INT_MIN;
        int maxf1 = 0;
        unordered_map<int,int>freq;
        while(r<n){
            freq[nums[r]]++;
            if(nums[r]==1){
                maxf1=max(maxf1,freq[nums[r]]);
            }
            int len=r-l+1;
            while((len-maxf1)>k){
                freq[nums[l]]--;
                if(nums[l]==1){
                    maxf1=max(maxf1,freq[nums[l]]);
                }
                l=l+1;
                len = r-l+1;
            }
            if((len-maxf1)<=k){
                len = r-l+1;
                maxlen=max(maxlen,len);
            }
            r++;
        }
        return maxlen;
    }
};