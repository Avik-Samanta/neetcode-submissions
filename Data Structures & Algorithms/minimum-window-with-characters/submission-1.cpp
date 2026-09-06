class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        unordered_map<char, int>countT, window;
        for(int i = 0; i < t.length(); i++){
            countT[t[i]]++;
        }
        int have = 0, need = countT.size();
        int resLen = INT_MAX;
        int l = 0;
        pair<int, int> res{-1, -1};

        for(int r = 0; r < s.length(); r++){
            window[s[r]]++;

            if(countT.count(s[r])){
                if(countT[s[r]] == window[s[r]]){
                    have++;
                }
            }

            while(have == need){
                if((r - l + 1) < resLen){
                    resLen = r - l + 1;
                    res = {l , r};
                }

                window[s[l]]--;
                if(countT.count(s[l])){
                    if(countT[s[l]] > window[s[l]]){
                        have--;
                    }
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
