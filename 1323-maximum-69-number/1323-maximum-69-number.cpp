class Solution {
public:
    int maximum69Number (int num) {
        int temp = 0, f = 0;
        int t = num, place = 1;
        while(t>9){
            place *= 10;
            t/=10;
        }
        cout<<place<<' ';
        while(place){
            int l = (num /place)%10;
            // cout<<l<<' ';
            if(!f && l == 6){
                temp = temp*10 + 9;
                f = 1;
            }
            else{
                temp = temp*10 + l;
            }
            // cout<<temp<<endl;
            place/=10;
        }
        return temp;
    }
};