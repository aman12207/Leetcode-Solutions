class Solution {
public:
    int nextGreaterElement(int n) {
        string s = "";
        bool isasc = false;
        while(n){
            char temp = (n%10) + '0';
            if(s.size()>0 && s[0]> temp) isasc = true;
            s = temp + s;
            n/=10;
        }
        if(!isasc) return -1;       // no possible int with greater value as n is in desc order
        int size = s.size();
        for(int i = size-2;i>=0;i--){
            char temp = 'a';
            int idx = 0;
            for(int j = i+1;j<size;j++){            // find nearest greater to right for each element 
                if(temp> s[j] && s[j] > s[i])   {
                    temp = s[j];
                    idx = j;
                }
            }
            if(temp != 'a'){                // if exist the swap the element with min element and sort the remianing string 
                int x = s[i];
                s[i] = s[idx];
                s[idx] = x;
                sort(s.begin()+i+1,s.end());
                break;
            }
        }
        return stol(s) <=INT_MAX ? stol(s) : -1;        // if no is out of range return -1
    }
};