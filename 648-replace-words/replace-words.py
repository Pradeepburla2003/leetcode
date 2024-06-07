class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        s=sentence.split(" ")
        ans=s
        for i in range(len(dictionary)):
            for j in range(len(s)):
                if(len(s[j])>len(dictionary[i]) and len(ans[j])>len(dictionary[i])):
                    # print(ans[j])
                    if(s[j][:len(dictionary[i])]==dictionary[i]):
                        ans[j]=dictionary[i]
        res=""
        for i in range(len(ans)-1):
            res+=ans[i]
            res+=" "
        res+=ans[-1]
        return res