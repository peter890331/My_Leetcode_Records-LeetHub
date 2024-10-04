// class Solution {
// public:
//     long long dividePlayers(vector<int>& skill) {
//         int n = skill.size();
//         long long total = 0;
//         unordered_map<int, int> players_map;
//         long long ans = 0;
//         int pair = 0;
        
//         for (int i=0; i<n; i++){
//             total += skill[i];
//             players_map[skill[i]]++;
//         }
//         total /= (n/2);
//         // cout<<"total: "<<total<<endl;

//         for (auto &[skill_, players]: players_map){
//             int remain = total - skill_;
//             // cout<<"skill_: "<<skill_<<", players: "<<players_map[skill_]<<endl;
//             // cout<<"n-skill_: "<<(remain)<<", players: "<<players_map[remain]<<endl;
//             if ((players_map.find(remain) == players_map.end()) || players_map[remain] != players){
//                 return -1;
//             }
//             else if (players_map[skill_] > 0 && players_map[remain] > 0) {
//                 // cout<<"skill_: "<<skill_<<", total-skill_: "<<total - skill_<<endl;
//                 // cout<<"skill_ * (total - skill_): "<<skill_ * (total - skill_)<<endl;
//                 if (skill_ == remain) pair = players_map[skill_]/2;
//                 else pair =  players_map[skill_];
//                 ans += (skill_ * remain) * pair;
//                 // cout<<"ans: "<<ans<<endl;
//                 players_map[skill_] -= pair;
//                 players_map[remain] -= pair;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // Step 1: Sort the skill array
        sort(skill.begin(), skill.end());
        
        int n = skill.size();
        int totalSkill = skill[0] + skill[n - 1]; // Required sum for each pair
        long long chemistrySum = 0;

        // Step 2: Pair players using two pointers
        for (int i = 0; i < n / 2; i++) {
            // Check if the sum of current pair matches the required totalSkill
            if (skill[i] + skill[n - i - 1] != totalSkill) {
                return -1; // Invalid configuration, return -1
            }
            // Calculate the chemistry (product of pair) and add it to the sum
            chemistrySum += (long long)skill[i] * skill[n - i - 1];
        }

        return chemistrySum; // Return total chemistry
    }
};

// withaarzoo's solution.
// two pointer.