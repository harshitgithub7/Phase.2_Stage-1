
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int maxLength = 0;  
        int start = 0;  

        for (int end = 0; end < s.length(); end++) {
            if (charMap.find(s[end]) != charMap.end() && charMap[s[end]] >= start) {
                start = charMap[s[end]] + 1; 
            }
            charMap[s[end]] = end; 
            maxLength = max(maxLength, end - start + 1); 
        }

        return maxLength;
    }
};
