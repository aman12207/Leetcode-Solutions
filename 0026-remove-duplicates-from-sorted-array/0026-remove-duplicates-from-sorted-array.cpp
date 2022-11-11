class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = unique(nums.begin(), nums.end());     // it places all the unique elements in the starting of the array   and return the it at last index of the unique array
        nums.erase(it, nums.end()); // we just have to remove the remaining elements
        return nums.size();
    }
};