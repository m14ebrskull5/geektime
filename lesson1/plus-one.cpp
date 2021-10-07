class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int pos =  digits.size() -1 ;
        while(true) {
            if(digits[pos] == 9) {
                digits[pos] = 0;

                if(pos == 0) {
                    digits.insert(digits.begin(), 1);
                    break;
                }
                pos--;
            } else {
                digits[pos] = digits[pos] + 1;
                break;;
            }
        }
        return digits;
    }
};