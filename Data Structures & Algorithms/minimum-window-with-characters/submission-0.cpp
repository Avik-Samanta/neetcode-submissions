class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";

        unordered_map<char, int> countT, window;
        for(char c: t){
            countT[c]++;
        }
        int have = 0, need = countT.size();
        pair<int, int> res;
        int resLen = INT_MAX;
        int l = 0;

        for(int r = 0; r < s.length(); r++){

            if(countT.count(s[r])){
                window[s[r]]++;
                if(window[s[r]] == countT[s[r]]){
                    have++;
                }
            }

            while(have == need){
                // update the res and reslen
                if((r - l + 1) < resLen){
                    resLen = r - l + 1;
                    res = {l, r};
                }
                if(countT.count(s[l])){
                    window[s[l]]--;
                    if(window[s[l]] < countT[s[l]]){
                        have--;
                    }
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
