#include <cmath>
#include <algorithm>

class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Calculate the angle of the minute hand from 12 o'clock
        double minute_angle = minutes * 6.0;
        
        // Calculate the angle of the hour hand from 12 o'clock
        // (hour % 12) ensures 12 o'clock is treated as 0
        double hour_angle = (hour % 12) * 30.0 + (minutes * 0.5);
        
        // Find the absolute difference between the two angles
        double angle_diff = std::abs(hour_angle - minute_angle);
        
        // Return the smaller of the two possible angles formed
        return std::min(angle_diff, 360.0 - angle_diff);
    }
};