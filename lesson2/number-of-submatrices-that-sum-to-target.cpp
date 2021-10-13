class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int s[m + 1][n + 1];
        memset(s, 0, sizeof s);
        int ans = 0;
        for(int i=1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        for(int i = 1; i <=m; i++) {
            for(int j = 1; j <=n; j++) {
                //每个元素的向00 扩展
                // 遍历子矩阵 k,p ~ i,j 的和
                for(int k = i; k >= 1; k--) {
                    for(int p = j; p >= 1; p--) {
                        int sum = s[i][j] - s[i][p - 1] - s[k - 1][j] + s[k - 1][p - 1];
                        if (sum == target)
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};