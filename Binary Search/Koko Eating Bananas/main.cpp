class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;  // Minimum possible eating speed
        int right = *max_element(piles.begin(), piles.end());  // Maximum possible eating speed

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canFinish(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool canFinish(const vector<int>& piles, int h, int speed) {
        int hours = 0;

        for (int bananas : piles) {
            hours += (bananas + speed - 1) / speed;  // Round up division
        }

        return hours <= h;
    }
};

