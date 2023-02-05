class Solution():
    def longestString(self, arr, n):
        #your code goes here
        
        arr.sort(key=len)
        valid = { '' }
        for s in arr:
            if s[:-1] in valid:
                valid.add(s)
        return min(valid,key=lambda x: (-len(x),x))
