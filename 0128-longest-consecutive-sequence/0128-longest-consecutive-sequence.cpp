class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> my_set;
        int length=nums.size();
        int longest=0;
        int count=0;

        for(int i=0;i<length;i++){
            my_set.insert(nums[i]);
        }

        for(int ele:my_set){
            if(my_set.find(ele-1)==my_set.end()){
                count=0;

                int j=0;
                while(my_set.find(ele+count)!=my_set.end()){
                    count++;

                }
                if(count>longest){
                    longest=count;
                }
            }
        }

        return longest; 
    }
};