class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int cnt=1;
        int maxi=1;
        if(nums.size()==0){
            return 0;
        }
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                cnt++;
            }
            else if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                cnt=1;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};