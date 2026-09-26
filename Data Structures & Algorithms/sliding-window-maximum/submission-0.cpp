class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int num = 0;
        vector<int> res;
        while(num < nums.size() - k + 1){
            int maxNum = INT_MIN;
            for(int i = 0; i < k; i++){
                maxNum = max(maxNum, nums[i + num]);
            }
            res.push_back(maxNum);
            num++;
        }
        return res;
    }
};