// 建立 Trie 樹。
class Trie {
public:
    Trie* children[26]; // 指向26個子節點的指針陣列，每個節點最多有 26 個子節點，對應英文字母 a 到 z。
    bool isEnd;         // 標記到該節點是否為 dictionary 中某個字根 (roots) 的結尾。

    // 構造函數。
    Trie() {                                // 初始化根節點。
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;          // 初始化所有子節點為空指針。
        }
        isEnd = false;                      // 初始化時並不是任何字根 (roots) 的結尾。
    }
};

class Solution {
public:
    Trie* root;                             // Trie 樹的根節點。

    Solution() {
        root = new Trie();                  // 初始化根節點。
    }

    // 將 dictionary 中的字根 (roots) 插入到 Trie 中。
    void insert(string word) {
        Trie* node = root;                          // 從根節點開始。
        for (char c : word) {                       // 遍歷字根 (roots) 的字母。
            int i = c - 'a';                        // 計算字母對應的索引。
            if (node->children[i] == nullptr) {
                node->children[i] = new Trie();     // 如果對應索引的子節點為空，則創建新節點。
            }
            node = node->children[i];               // 移動到對應索引的子節點。
        }
        node->isEnd = true;                         // 字根 (roots) 插入結束，將結尾標記為 true。
    }

    // 查找單詞的最短前綴，如果存在則返回前綴，也就是某個字根 (roots)，否則返回單詞本身。
    string search(string word) {
        Trie* node = root;                          // 從根節點開始。
        string result;
        for (char c : word) {                       // 遍歷單詞的字母。
            int i = c - 'a';                        // 計算字母對應的索引。
            if (node->children[i] == nullptr) {
                return word;                        // 如果對應索引的子節點為空，則返回單詞本身。
            }
            result += c;                            // 如果對應索引的子節點不為空，將當前字母加入結果中。
            if (node->children[i]->isEnd) {         
                return result;                      // 如果當前子節點被標記為某個字根 (roots) 的結尾，返回當前結果，也就是該字根 (roots) 。
            }
            node = node->children[i];               // 移動到對應索引的子節點。     
        }
        return word;                                // 如果沒有找到任何字根 (roots)，返回單詞本身。
    }

    // 替換句子中的單詞為字典中的最短前綴，可能是某個字根 (roots) 或是單詞本身。
    string replaceWords(vector<string>& dictionary, string sentence) {
        for (string word : dictionary) {
            insert(word);               // 將 dictionary 中的字根 (roots) 插入到 Trie 中。
        }

        stringstream ss(sentence);      // 使用字符串流來分割句子中的單詞。stringstream 是 C++ 一個專門處理讀取、寫入、處理字串的一個類別。
        string word, result;
        while (ss >> word) {            // 使用 >> 操作符從字符串流中提取單詞。
            if (!result.empty()) {
                result += " ";          // 若 result 中已有某個字根 (roots) 或是單詞本身，添加空格分隔。
            }
            result += search(word);     // 將單詞替換為字典中的最短前綴，可能是某個字根 (roots) 或是單詞本身。
        }
        return result;
    }
};

// 字典樹 (Trie)。
// lancertech6's solution.
// Reference from 贾考博 LeetCode 648. Replace Words, https://youtu.be/jzSIMq53_P0.