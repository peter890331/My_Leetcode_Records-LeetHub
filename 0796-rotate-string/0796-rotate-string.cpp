class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s+s).find(goal) != string::npos;
    }
};

// Piotr Maminski's solution.
// An-Wen Deng's solution.
// Reference from C++ std::string::find 搜尋字串用法與範例, https://shengyu7697.github.io/std-string-find/.