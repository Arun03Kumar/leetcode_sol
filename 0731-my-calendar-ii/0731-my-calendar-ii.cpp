class MyCalendarTwo {
public:
    vector<pair<int, int>> double_booked_regions;
    vector<pair<int, int>> over_all_bookings;

    bool check_overlap(int s1, int e1, int s2, int e2) {
        return max(s1, s2) < min(e1, e2);
    }

    pair<int, int> find_overlapping_region(int s1, int e1, int s2, int e2) {
        return {max(s1, s2), min(e1, e2)};
    }

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto region: double_booked_regions) {
            if(check_overlap(start, end, region.first, region.second)) {
                return false;
            }
        }

        for(auto bookings: over_all_bookings) {
            if(check_overlap(start, end, bookings.first, bookings.second)) {
                auto new_overlapped_region = find_overlapping_region(start, end, bookings.first, bookings.second);
                double_booked_regions.push_back(new_overlapped_region);
            }
        }

        over_all_bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */