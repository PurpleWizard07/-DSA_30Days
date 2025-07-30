class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1;
        int maxSpeed = 0;
        //finding max pile size
        for(int pile: piles) {
            maxSpeed = max(maxSpeed, pile);
        }
        int ans = maxSpeed;

        //Binary Search
        while(minSpeed <= maxSpeed) {
            int mid = minSpeed + (maxSpeed - minSpeed)/2;

            long long hours = 0;
            for(int pile: piles) {
                hours += (pile + mid - 1) / mid;
            }
                //simulates ceil(pile/mid). take eg pile=10, mid=3.
                // ceil(10/3)=4, 10+3-1/3 = 12/3=4.
                // pile=9, mid=3. ceil(9/3)=3, 9+3-1/3 = 11/3=3.

            if(hours <= h) {
                ans = mid;
                maxSpeed = mid-1;
            } else {
                minSpeed = mid+1;
            }
        }
        return ans;

    }
};
