class Solution {
public:
    bool winnerOfGame(string colors) {
        int count_alice = 0 , count_bob = 0;
        int n = colors.size();
        for(int i = 0;i<n-2;i++){
            string s = colors.substr(i,3);
            if(s == "AAA" ) count_alice++;
            if(s == "BBB") count_bob++;
        }
        cout<<count_alice<<' '<<count_bob<<endl;
        return count_alice>count_bob;
    }
};