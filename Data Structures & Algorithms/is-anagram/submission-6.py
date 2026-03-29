class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        #my approach rn: make 2 hash set that
        #increments value of key by 1 everytime
        #the letter is used in a string, then return
        #hash set == other hash set

        #remember to always handle edge/base cases
        if len(s) != len(t):
            return False

        set1 = {}
        set2 = {}
        for c in s:
            set1[c] = set1.get(c, 0) + 1
        for c in t:
            set2[c] = set2.get(c, 0) + 1
        return set1 == set2