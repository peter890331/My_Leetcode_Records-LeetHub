class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {

        map<char, int> char_map;
        for (char ch: s){
            char_map[ch]++;
        }

        priority_queue<pair<char, int>> char_priority_queue;
        for (auto it: char_map){
            char_priority_queue.push(make_pair(it.first, it.second));
        }

        string ans;
        while(!char_priority_queue.empty()){
            auto first_it = char_priority_queue.top();
            char_priority_queue.pop();
            char first_ch = first_it.first;
            int first_ch_temp_count = first_it.second;
            int first_ch_real_count = min(first_ch_temp_count, repeatLimit);
            ans.append(first_ch_real_count, first_ch);
            first_ch_temp_count -= first_ch_real_count;
            if (first_ch_temp_count > 0){
                if (!char_priority_queue.empty()){
                    auto second_it = char_priority_queue.top();
                    char_priority_queue.pop();
                    char second_ch = second_it.first;
                    int second_ch_temp_count = second_it.second;
                    ans.append(1, second_ch);
                    second_ch_temp_count -= 1;
                    if (second_ch_temp_count > 0){
                        char_priority_queue.emplace(second_ch, second_ch_temp_count);
                    }
                }
                else {
                    return ans;
                }
                char_priority_queue.emplace(first_ch, first_ch_temp_count);
            }
        }
        return ans;
    }
};

// Reference from jflkasdjflda's solution.
// Reference from Jai Taneja's solution.