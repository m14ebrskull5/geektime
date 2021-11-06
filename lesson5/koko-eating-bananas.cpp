class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        for(int pile: piles) {
            right = max(pile, right);
        }
        check(piles, h, 4);
        // cout << right << endl;
        while(left < right) {
            int mid = (left + right) /2;

            if(check(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

    bool check(vector<int>& piles, int h, int spd) {
        long time = 0;
        for (int p: piles) {
            if(p%spd == 0) {
                time += p/spd;
            } else {
                time += p/spd + 1;
            }
        }

        return time <= h;
    }
};