class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(auto i : nums){
            s.insert(i);
        }
        int count = 0;
        for(auto it = s.rbegin(); it!= s.rend();it++){      // traversing 
            count++;
            if(count == 3) return *it;
        }
        return *(s.rbegin());
    }
};