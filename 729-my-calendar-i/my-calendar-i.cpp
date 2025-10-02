class MyCalendar {
private:
    set<pair<int,int>> calendar;
public:
    MyCalendar() {
        calendar=set<pair<int,int>>();
    }
    
    bool book(int startTime, int endTime) 
    {
        pair<int,int> event={startTime, endTime};
        const auto nextEvent=calendar.lower_bound(event);
        if(nextEvent!=calendar.end() && nextEvent->first < endTime) //overlapping
            return false;
        if(nextEvent!=calendar.begin()){
            const auto prevEvent=prev(nextEvent);
            if(prevEvent->second > startTime) //overlapping
                return false;
        }
        calendar.insert(event);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */