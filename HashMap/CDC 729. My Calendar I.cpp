

729. My Calendar I
Medium

1064

45

Add to List

Share
Implement a MyCalendar class to store your events. A new event can be added if adding the event will not cause a double booking.

Your class will have the method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A double booking happens when two events have some non-empty intersection (ie., there is some time that is common to both events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
Example 1:

MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(15, 25); // returns false
MyCalendar.book(20, 30); // returns true
Explanation: 
The first event can be booked.  The second can't because time 15 is already booked by another event.
The third event can be booked, as the first event takes every time less than 20, but not including 20.
 

Note:

The number of calls to MyCalendar.book per test case will be at most 1000.
In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].



class MyCalendar {
private:
    vector<pair<int, int>> mp;
public:
    MyCalendar() { }
    
    bool book(int start, int end) {
        //If first booking, book the date in mp and return true
        if(mp.size() == 0)
        {
            mp.push_back({start, end});
            return true;
        }
        else
        {
            //Iterate through the mp vector and make sure there are no conflicts.
            for(int i = 0; i < mp.size(); i++)
            {
                //If event start after start of one event and ends before the same, return false
                if(start >= mp[i].first && start < mp[i].second) return false;
                //If event starts before one event and ends after it, then it is overlapping, return false.
                if(start <= mp[i].first && end > mp[i].first) return false;
            }
            mp.push_back({start, end});
            return true;
        }
    }
};

