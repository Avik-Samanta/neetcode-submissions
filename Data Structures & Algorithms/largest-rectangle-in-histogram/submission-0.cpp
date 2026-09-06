class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> stack; // {index, height}
        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!stack.empty() && stack.top().second > heights[i]){
                auto pair = stack.top(); stack.pop();
                maxArea = max(maxArea, pair.second * (i - pair.first));
                start = pair.first;
            }
            stack.push({start, heights[i]});
        }
        while(!stack.empty()){
            auto p = stack.top();
            stack.pop();
            maxArea = max(maxArea, p.second * ((int)heights.size() - p.first));
        }
        return maxArea;
    }
};
