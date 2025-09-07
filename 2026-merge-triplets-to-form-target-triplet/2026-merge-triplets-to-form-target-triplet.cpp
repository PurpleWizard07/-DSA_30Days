class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool found0 = false;
        bool found1 = false;
        bool found2 = false;
        
        for (auto& triplet : triplets) {
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) {
                continue;
            }
            
            if (triplet[0] == target[0]) found0 = true;
            if (triplet[1] == target[1]) found1 = true;
            if (triplet[2] == target[2]) found2 = true;
        }
        
        return found0 && found1 && found2;
    }
};
