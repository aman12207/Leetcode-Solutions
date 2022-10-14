class Solution {
public:
    int countQuadruplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        freq[arr[n - 1]] = 1;
        int answ = 0;
        for (int i = n - 2; i > 1; --i)
        {
            for (int j = i - 1; j > 0; --j)
            {
                for (int k = j - 1; k >= 0; --k)
                {
                    if (freq.count(arr[i] + arr[j] + arr[k]))
                    {
                        answ += freq[arr[i] + arr[j] + arr[k]];
                    }
                }
            }
            freq[arr[i]] += 1;
        }
        return answ;
    }
};