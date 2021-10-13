class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            auto iter = m.find(nums[i]);
            if(iter == m.end()) {
                //没找到
                vector<int> a;
                m[nums[i]] = a;
            }

            m[nums[i]].push_back(i);
        }
        vector<int> maxkey;
        maxkey = findMaxKey();
        int minlength = 50000;
        for(auto i : maxkey) {
            if(m[i][m[i].size() -1] - m[i][0] < minlength) {
                minlength = m[i][m[i].size() -1] - m[i][0] + 1;
            }
        }
        return minlength;
    }

private:
    unordered_map<int, vector<int>> m;
    vector<int> findMaxKey() {
        int maxsize = 0;
        vector<int> maxkey;
        for(auto kv: m) {
            if(kv.second.size() > maxsize) {
                maxsize = kv.second.size();
            }
        }

        for(auto kv: m) {
            if(kv.second.size() == maxsize) {
                maxkey.push_back(kv.first);
            }
        }
        return maxkey;
    }

};