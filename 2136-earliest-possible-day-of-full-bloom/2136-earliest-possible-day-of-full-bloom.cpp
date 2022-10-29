class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        std::pmr::monotonic_buffer_resource mbr;
        std::pmr::vector<pair<int,int>> plants {&mbr};
        plants.resize(growTime.size());
        
        for (int index = 0; index < growTime.size(); ++index) {
            plants[index].first = growTime[index];
            plants[index].second = plantTime[index];
        }
        
        sort(plants.begin(), plants.end(), greater<pair<int,int>>());
        
        int result = 0;
        int acc = 0;
        for (auto &plant : plants) {
            //cout << plant.first << " " << plant.second << endl;
            result = max(result, acc + plant.first + plant.second);
            acc += plant.second;
        }
        return result;
    }
};