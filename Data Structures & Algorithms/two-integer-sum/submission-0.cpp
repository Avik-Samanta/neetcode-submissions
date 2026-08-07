class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> A;
        for (int i = 0; i < nums.size(); i++) {
            A.push_back({nums[i], i});
        }
        sort(A.begin(), A.end());

        int i = 0, j = A.size() - 1;
        while (i < j) {
            int current = A[i].first + A[j].first;
            if (current == target) {
                return {min(A[i].second, A[j].second), max(A[i].second, A[j].second)};
            } else if (current < target){
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};
