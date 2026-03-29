class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        #my approach: declare a diff variable in for loop
        #that loops through and sees each and adds to seen

        #before we were using a set, but we should
        #usually be using a dict so we can return the indices
        #rather than the actual values, because
        #a set only has the values themselves
        #rather than the indices, key, value, etc.
        #in the map, we want to store the key as the
        #number in loop and the indices as the value
        seen = dict()
        for i, num in enumerate(nums):
            diff = target - num
            if diff in seen:
                return [seen[diff], i] #indices
            seen[num] = i #store this index
    