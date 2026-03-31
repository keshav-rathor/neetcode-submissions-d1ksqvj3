/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end(), [](Interval a, Interval b) {
            return a.start < b.start;
        });
        
        for (int i = 1; i < n; i++) {
            if (nums[i].start < nums[i-1].end) {
                return false;
            }
        }
        
        return true;
    }
};
