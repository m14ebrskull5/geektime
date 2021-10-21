class Solution {
public:
    vector<vector<bool>> v;
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        v = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i==0 || j ==0 || i == m -1 || j==n -1) {
                    //处于边界
                    if(board[i][j] =='O') {
                        q.push({i,j});
                        v[i][j] = true;
                    }
                }
            }
        }
        int dx[4] = { -1, 0 ,0, 1 };
        int dy[4] = { 0, -1, 1, 0 }; 
        while(!q.empty()) {
            pair<int,int> p = q.front();
            int x = p.first;
            int y = p.second;

            q.pop();
            for(int i = 0; i < 4 ;i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= m || nx < 0 || ny < 0 || ny >= n) {
                    //出界
                    continue;
                }

                if(board[nx][ny] == 'X') continue;

                if(v[nx][ny]) continue;

                q.push({nx,ny});
                v[nx][ny] = true;
            }

        }

        //清除不在v的X
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(v[i][j]) continue;
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};