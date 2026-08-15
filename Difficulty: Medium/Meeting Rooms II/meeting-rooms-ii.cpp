class Solution {
public:
    int minMeetingRooms(vector<int> &s, vector<int> &e) {
        int n = s.size();

        if (n == 0) return 0;

        sort(s.begin(), s.end());
        sort(e.begin(), e.end());

        int i = 0, j = 0;
        int rooms = 0;
        int maxRooms = 0;

        while (i < n) {
            // New meeting starts before previous meeting ends
            if (s[i] < e[j]) {
                rooms++;
                maxRooms = max(maxRooms, rooms);
                i++;
            }
            else {
                // s[i] >= e[j]
                // A meeting ended, so its room can be reused
                rooms--;
                j++;
            }
        }
        return maxRooms;
    }
};