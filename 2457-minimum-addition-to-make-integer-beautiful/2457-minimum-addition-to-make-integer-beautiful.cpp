class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        string s = to_string(n);        // storing n to string
        long long ans = 0;
        int size = s.size(), sum = 0;
        for(int i = 0;i<size;i++) sum+= (s[i] - '0');       
        if(sum <= target) return 0;     // if current no is also valid return 0; 
        sum = 0;        
        for(int i = 0;i<size;i++){      // traversing the string 
            sum += (s[i] - '0');
            if(sum >= target ){         // first index where prefix index >= target convert it to nearest mulitplle like it 435 and at index 1 sum >= target convert it to 500
                for(int  j = i;j<size;j++){     // converting all the indexing from i to size to 0
                    s[j] = '0';
                }
                if(i != 0){     // and inc the index-1 by 1 which will convert the no
                    cout<<s[i-1]<<' ';
                    s[i-1]++;
                    cout<<s[i-1]<<' ';
                }
                break;
            }
        }
        cout<<s<<endl;
        if(s[0] == '0') ans = 1;        // it means the no at first index is greater than target
        // like 432 and target is 3 the we have to convert it to 1000
        for(auto i : s){
            ans = ans*10 + (i-'0');
        }
        ans -= n;
        return ans;
    }
};