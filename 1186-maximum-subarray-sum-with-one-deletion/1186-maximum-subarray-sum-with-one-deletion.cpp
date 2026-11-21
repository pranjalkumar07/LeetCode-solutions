class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        int maxEnd=arr[0];
        int maxDel=INT_MIN;

        int res=arr[0];

        for(int i=1; i<n; i++) {

            int v1=arr[i];
            int v2=maxEnd + arr[i];

            int v3=(maxDel == INT_MIN) ? INT_MIN : maxDel+arr[i];

            maxDel = max(v3,maxEnd);
            maxEnd = max(v1,v2);

            res = max(res, max(maxEnd,maxDel));
        }

        return res;
    }
};
