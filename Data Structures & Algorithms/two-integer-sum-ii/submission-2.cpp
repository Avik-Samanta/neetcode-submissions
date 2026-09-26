class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while(l < r){
            int total = numbers[l] + numbers[r];
            if(total == target){
                return {numbers[l], numbers[r]};
            } else if(total < target){
                l++;
            } else {
                r--;
            }
        }
        return {};
    }
};
