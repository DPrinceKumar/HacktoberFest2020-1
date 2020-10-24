'''
*
* Solution to Longest Substring without Repeating characters at LeetCode in Python
*
* author: SameerShanbhag
* ref: https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
*
'''

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest = 0
        sub_str = ''
        counter = 0

        while counter != len(s):
            if s[counter] not in sub_str:
                sub_str += s[counter]
                counter += 1
            else:
                s = s[s.index(s[counter]) + 1:]
                if len(sub_str) > longest:
                    longest = len(sub_str)
                sub_str = ''
                counter = 0

        if len(sub_str) > longest:
            longest = len(sub_str)

        return longest