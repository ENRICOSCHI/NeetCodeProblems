class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());
        double time = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            double t = (target - cars[i].first) * 1.0 / cars[i].second;
            if (t > time) {
                res++;
                time = t;
            }
        }
        return res;
    }
};
