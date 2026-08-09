class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j){
            int total = numbers[i] + numbers[j];
            if(total == target){
                return {i+1, j+1};
            } else if( total < target){
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};
