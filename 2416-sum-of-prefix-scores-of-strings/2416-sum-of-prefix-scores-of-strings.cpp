struct Trie {
    int score; // 记录该节点的前缀得分（有多少个单词经过这个节点）
    Trie *children[26]; // 用来存储26个字母的分支（a-z）
    
    // Trie构造函数，初始化score为0，所有children为NULL
    Trie () {
        score = 0;
        memset(children, 0, sizeof(children)); // 将children数组全部初始化为0
    }
    
    // 添加单词到Trie的函数
    void add(string &s, int i) {
        if (i) score++; // 如果i不为0，表示有新单词经过这个前缀，增加得分
        if (i == s.size()) return; // 如果i等于字符串长度，表示单词已经插入完成，返回
        int idx = s[i] - 'a'; // 计算当前字符在children数组中的索引位置
        if (!children[idx]) children[idx] = new Trie(); // 如果该分支不存在，则新建一个Trie节点
        children[idx]->add(s, i + 1); // 递归处理下一个字符
    }
    
    // 深度优先搜索（dfs）来计算当前单词的前缀得分
    int dfs(string &s, int i) {
        if (i == s.size()) return score; // 如果i等于字符串长度，返回当前节点的得分
        int idx = s[i] - 'a'; // 计算当前字符在children数组中的索引位置
        return score + children[idx]->dfs(s, i + 1); // 返回当前节点的得分加上后续字符的得分
    }
};

class Solution {
public:
    // 计算每个单词的前缀得分
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *trie = new Trie(); // 创建一个Trie
        // 将每个单词添加到Trie中
        for (string &s : words) {
            trie->add(s, 0); // 从第0个字符开始插入单词
        }

        vector<int> res; // 用来存储结果
        // 计算每个单词的前缀得分
        for (string &s : words) {
            res.push_back(trie->dfs(s, 0)); // 从第0个字符开始递归计算得分
        }

        return res; // 返回结果向量
        
    }
};

// 字典樹 (Trie)。
// Rzhek's solution.