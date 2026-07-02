class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        
        string call = countAndSay(n-1);
        //processing
        string res="";
        for(int i=0;i<call.size();i++){
            char ch=call[i];
            int cnt=1;

            while(i<call.size()-1 && call[i]==call[i+1]){
                cnt++;
                i++;
            }
            res += to_string(cnt) + string(1,ch);
        }
        return res;
    }
};