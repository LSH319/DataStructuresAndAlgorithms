#include <unordered_map>
#include <unordered_set>

/*
twoSum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 */

/*
Maximum Subarray
Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 
Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

/*
moveZeroes
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]

Constraints:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
*/

/*
Contains Duplicate
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109
 */

/*
Rotate Array
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Constraints:
1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 */

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> targetSub;
        for(int i = 0; i < nums.size(); i++){
            int needNum = target - nums[i];
            if(targetSub.find(needNum) != targetSub.end())
            {
                return {targetSub[needNum],i};
            }
            targetSub[nums[i]] = i;
        }
        return {};
    }

    int maxSubArray(std::vector<int>& nums) {
        int answer = nums[0];
        int sum = nums[0];
        for(int i=1; i< nums.size(); i++){
            sum = std::max(nums[i],sum + nums[i]);
            answer = std::max(sum,answer);
        }
        return answer;
    }
    
    void moveZeroes(std::vector<int>& nums) {
        int index = 0;
        for(int i=0; i<nums.size()-1;i++){
            if(nums[i] == 0){
                while(nums[index] == 0){
                    index++;
                    if(index >= nums.size()) return;
                }
                std::swap(nums[i],nums[index]);
                if(index >= nums.size()-1) return;
            }else{
                if(index == i) index ++;
            }
        }
    }

    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> innerNum;
        for(int i=0; i<nums.size(); i++){
            if(innerNum.find(nums[i]) != innerNum.end()) return true;
            innerNum.insert(nums[i]);
        }
        return false;
    }

    void rotate(std::vector<int>& nums, int k) {
        int remain = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+remain);
        reverse(nums.begin()+remain, nums.end());
    }
};

int main(int argc, char* argv[])
{
    return 0;
}

