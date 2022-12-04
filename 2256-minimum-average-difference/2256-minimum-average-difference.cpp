class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> prefix;         
        long long n= nums.size(), sum = 0;
        for(auto i : nums){             // store prefix sum
            sum+= i;
            prefix.push_back(sum);
        }
        long long ans = INT_MAX, minIdx = 0;
        for(int i = 0;i<n;i++){
            long long preAvg = (prefix[i]/(i+1));         // avg of first i elements
            long long remAvg = 0;
            if(i != n-1)                    // in case of last element n - i - 1 will be 0
                remAvg = ((sum-prefix[i])/(n-i-1));     // avg of remaining elements
            long long diff = abs(preAvg - remAvg );
            // cout<<preAvg<<" "<<remAvg<<" "<<diff<<endl;
            if(diff < ans) {
                ans = diff;
                minIdx = i;                         // update ans and idx
            }
        }
        return minIdx;
    }
};