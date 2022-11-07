class SeatManager {
public:
    priority_queue<int, vector<int> , greater<int>> pq;     // store unreserve seats in pq
    int size = 0, available = 0;
    SeatManager(int n) {        // unreserve n seates
        for(int i = 1;i<=n;i++){
            pq.push(i);
        }
        size = n;
    }
    
    int reserve() {         //pop unreserve seat with minm index
        int temp = pq.top();
        pq.pop();
        return temp;
    }
    
    void unreserve(int seatNumber) {        // add unreserve seat
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */