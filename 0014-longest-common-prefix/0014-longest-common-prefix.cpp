class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min=INT_MAX;
        int cnt=0;
        string res;
        for(int i=0;i<strs.size();i++){
            int len=strs[i].length();
            if(len<min){
                min=len;
                res=strs[i];
            }
        }
        for(int i=0;i<min;i++){
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]!=res[i]){
                    res=res.substr(0,cnt);
                }
            }
            cnt++;
        }
        if(strs.size()==0){
            return "";
        }
        return res;
    }
};