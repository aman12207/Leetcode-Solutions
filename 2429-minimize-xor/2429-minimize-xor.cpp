class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bitsinN1= 0 , bitsinN2 = 0;
        for(int i = 0 ;i<=31;i++){          // count bits in both number
            int mask = 1<<i;
            if((mask & num1) > 0 ) bitsinN1++;
            if((mask & num2) > 0 ) bitsinN2++;
        }
        int ans = 0;
        if(bitsinN1 == bitsinN2) return num1;
        if(bitsinN1 < bitsinN2){
            ans = num1;                     // to minimise the xor set the ans as num1
            bitsinN2-= bitsinN1;
            for(int i = 0 ;i<=31;i++){       // setting the remaining bits as minm as possible
                int mask = 1<<i;
                if((mask & ans) == 0 ){
                    ans = ans| mask;
                    bitsinN2--;
                }
                if(bitsinN2 == 0 ) return ans;
            }
        }
        if(bitsinN1 > bitsinN2){
            for(int i = 31 ;i>=0;i--){       // setting the same bits to minimise xor
                int mask = 1<<i;
                if((mask & num1) > 0 ){
                    ans = ans| mask;
                    bitsinN2--;
                }
                if(bitsinN2 == 0 ) return ans;
            }
            
        }
        return ans;
    }
};