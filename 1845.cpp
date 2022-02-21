class SeatManager {
private:
    vector<int> heap;

public:
    SeatManager(int n) {
        for (int i = 0; i < n; i++) heap.emplace_back(i 
        + 1);
        make_heap(heap.begin(), heap.end(), greater<int>());
    }
    
    int reserve() {
        int res = heap.front();
        pop_heap(heap.begin(), heap.end(), greater<int>());
        heap.pop_back();
        return res;
    }
    
    void unreserve(int seatNumber) {
        heap.push_back(seatNumber);
        push_heap(heap.begin(), heap.end(), greater<int>());
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */