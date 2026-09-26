class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j){
            int total = numbers[i] + numbers[j];
            if(total == target){
                return {numbers[i], numbers[j]};
            } else if( total < target){
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};
