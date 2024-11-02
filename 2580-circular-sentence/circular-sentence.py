class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        a = sentence.split(" ")
        temp = a[0]
        for i in range(1,len(a)):
            if(a[i][0] != temp[-1]): return False
            temp = a[i]
        if(temp[-1] != a[0][0]): return False
        return True