class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;

        if(left == right) {
            return target == matrix[0][0];
        }
        cout << right << endl;
        while(left < right) {
            int mid = (left + right) /2;

            int row = mid / n;
            int col = mid % n;
            // cout << row << "," << col << "..."  << mid << endl;
            if(target == matrix[row][col]) return true;

            if(target > matrix[row][col]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        // return true;
        return matrix[left/n][left%n] == target;

    }
};