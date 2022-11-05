static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        k %= std::accumulate(cbegin(chalk), cend(chalk), 0LL);
        for (auto i = 0; i < chalk.size(); ++i){
            k -= chalk[i];
            if (k < 0)
                return i;
        }
        return 0;
    }
};