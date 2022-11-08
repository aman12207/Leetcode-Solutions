class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int f = 0,n = nums.size();
        for(int i= n-2;i>=0;i--){
            int minm = INT_MAX, minIdx = -1;
            for(int j = i+1;j<n;j++){
                if(minm > nums[j] && nums[j]> nums[i]){
                    minm = nums[j];
                    minIdx = j;
                }
            }
            cout<<nums[i]<<' ' <<minm<<endl;
            if(minIdx != -1){          // just swap last pair which is in ascending order
                f = 1;
                int temp = nums[i];
                nums[i] = nums[minIdx];
                nums[minIdx] = temp;
                sort(nums.begin()+i+1,nums.end());
                break;
            }
        }
        if(!f) sort(nums.begin(),nums.end());       // if array is sorted in desc order sort as there is no arrangement with greater lexographical value
    }
};

//1 7 5 9 7 2 