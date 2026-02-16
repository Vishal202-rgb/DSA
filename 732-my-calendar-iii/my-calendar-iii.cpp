class MyCalendarThree {
public:
    map<int,int>events;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        events[startTime]+=1;
        events[endTime]-=1;

        int count=0;
        int maxInt=0;

        for(auto &it:events){
            count+=it.second;
            maxInt=max(maxInt,count);
        }
        return maxInt;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */