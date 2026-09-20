class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> temp = board;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cnt1=0;

                for(int delrow=-1; delrow<=1;delrow++){
                    for(int delcol=-1;delcol<=1;delcol++){
                        if(delrow==0 && delcol==0){
                            continue;
                        }
                        int nrow= i+delrow;
                        int ncol = j + delcol;
                        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol]==1){
                            cnt1++;
                        }
                    }
                }
                if(board[i][j]==1){
                    if(cnt1<2 || cnt1>3){
                        temp[i][j]=0;
                    }
                }
                else{
                    if(cnt1==3){
                        temp[i][j]=1;
                    }
                }
            }
        }
        board=temp;
    }
};