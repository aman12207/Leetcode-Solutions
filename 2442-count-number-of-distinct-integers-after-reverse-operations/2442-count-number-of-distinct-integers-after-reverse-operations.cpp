class Solution {
public:
    int rev (int n){        // just find the reverse an
        int temp = 0;
        while(n>0){
            temp = temp*10 + n%10;
            n/=10;
        }
        return temp;
    }
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s;
        for(auto i : nums){
            s.insert(i);
            s.insert(rev(i));
        }
        return s.size();
    }
};