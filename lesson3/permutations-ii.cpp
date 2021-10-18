class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums){
        sort(nums.begin(), nums.end());
        
        this->n = nums.size();
        this->nums = nums;
        used = vector<bool>(nums.size(), false);
        dfs(0);
        return ans;
    }

    void dfs(int pos) {
        // i 是 現在填充的位置
        
        if(pos == n) {
            ans.push_back(chosen);
            return;
        }
        for(int k = 0; k < n; k++) {
            if(used[k] || (k  > 0 && nums[k] == nums[k -1] && !used[k -1])) continue; //限制只能按順序插入重複元素
            if(!used[k]) {
                used[k] = true;
                chosen.push_back(nums[k]);

                dfs(pos + 1);
                chosen.pop_back();
                used[k] = false;
            }
        }
        // used.clear();
    }
private:
    int n;
    vector<vector<int>> ans;
    vector<bool> used;
    vector<int> chosen;
    vector<int> nums;
};