'''
*
* Solution to Valid Parantheses at LeetCode in Python
*
* author: SameerShanbhag
* ref: https://leetcode.com/problems/valid-parentheses/
*
'''


class Solution:
    def isValid(self, s: str) -> bool:
        seq = []

        for i in s:
            if i == '[':
                seq.append(']')
            elif i == '(':
                seq.append(')')
            elif i == '{':
                seq.append('}')
            else:
                if len(seq) > 0 and seq[-1] == i:
                    seq = seq[:-1]
                else:
                    return False
        if len(seq) > 0:
            return False
        else:
            return True
