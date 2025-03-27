// https://www.interviewbit.com/problems/meeting-rooms/

class Event {
    public:
        Event(int t, bool s) {
            time = t;
            isStart = s;
        }
    
        int time;
        bool isStart;
};

bool comp(Event e1, Event e2) {
    if (e1.time == e2.time) {
        return !e1.isStart;
    }
    return e1.time < e2.time;
}

int Solution::solve(vector<vector<int> > &A) {
    vector<Event> events;
    for (auto a: A) {
        events.push_back(Event(a[0], true));
        events.push_back(Event(a[1], false));
    }
    
    sort(events.begin(), events.end(), comp);
    
    int ret = 0, retMax = 0;
    for (auto e: events) {
        if (e.isStart) ret++;
        else ret--;
        ret = max(ret, 0);
        retMax = max(retMax, ret);
    }
    
    return retMax;
}
