class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        #declare the has set
        dup = set()
        #when going thru for loop, python 
        #automatically sets loop variable in this case
        # 'num' to get the value from the array or whatever
        for num in nums:
            if num in dup:
                return True
            dup.add(num)
        return False