class Solution {
public:
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
vector<int> result;
deque<int> dq;

    for (int i = 0; i < nums.size(); i++) {
        // remove indices outside the current window
        if (!dq.empty() && dq.front() < i-k+1) {
            dq.pop_front();
        }
        
        // remove indices with smaller values
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        // add index to deque
        dq.push_back(i);
        
        // add maximum element to result
        if (i >= k-1) {
            result.push_back(nums[dq.front()]);
        }
    }
    
    return result;
}
};
