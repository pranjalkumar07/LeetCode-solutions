class Solution {
public:
    string removeKdigits(string num, int k) {
        string st="";
        for(char digit:num){
            while(!st.empty()&& k>0 && st.back()>digit){
                st.pop_back();
                k--;
            }
            st.push_back(digit);
        }
        //if k is not zero still
        while(k>0){
            st.pop_back();
            k--;
        }
        //removing leading zeros
        int i=0;
        while(i<st.size() && st[i]=='0'){
            i++;
        }
        st=st.substr(i);
        return st.empty()? "0":st;
    }
};