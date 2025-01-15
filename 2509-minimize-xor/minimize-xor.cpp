class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bitsNum1 = __builtin_popcount(num1);
        int bitsNum2 = __builtin_popcount(num2);

        int ans = 0;

        if(bitsNum1 <= bitsNum2) {
            int extra = bitsNum2 - bitsNum1;
            ans = num1;
            for(int i = 0; i < 32; i++) {
                if((num1 & (1 << i)) == 0 && extra) {
                    ans |= (1 << i);
                    extra--;
                }
            }
        }
        else {
            for(int i = 31; i >= 0; i--) {
                if((num1 & (1 << i))) {
                    if(bitsNum2) {
                        bitsNum2--;
                        ans |= (1 << i);
                    }
                }
            }
        }

        return ans;
    }
};