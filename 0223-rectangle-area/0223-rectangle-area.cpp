class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area = ((ax2 - ax1) * (ay2 - ay1)) + ((bx2 - bx1) * (by2 - by1));
        // we found the area without excluding any overlapping area = l*b
        // cout<<area<<endl;
        if((bx2>= ax1 && bx1 <= ax2) && (by2>= ay1 && by1<= by2)){
            int y1 = max((ay1), (by1));
            int x1 = max((ax1), (bx1));
            int y2 = min((ay2), (by2));
            int x2 = min((ax2), (bx2));
            int xoverlap = x2-x1, yoverlap = y2-y1;
            // cout<<xoverlap<<' '<<yoverlap<<endl;
            if(xoverlap>0 && yoverlap>0)
                area -= xoverlap*yoverlap;
        }
        return area;
    }
};   