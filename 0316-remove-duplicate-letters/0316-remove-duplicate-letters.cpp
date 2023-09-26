class Solution {
public:
    string removeDuplicateLetters(string s) {
    vector<int> cand(26, 0);
    vector<bool> visited(26, false);
    for (char c : s)
        cand[c-'a']++;
    string result = "";
    for (char c : s) {
        cand[c-'a']--;
        if (visited[c-'a']) continue;
        while (result.size()>0 && c-'a' < result.back()-'a' && cand[result.back()-'a']) {
            visited[result.back()-'a'] = false;
            result.pop_back();
        }
        result.push_back(c);
        visited[c-'a'] = true;
    }
    return result;
    }
};