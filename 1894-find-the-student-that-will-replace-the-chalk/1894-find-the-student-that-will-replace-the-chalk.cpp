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