class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        cache = []
        def dp(rem: str):
            for word in wordDict:
                if rem in cache:
                    return False
                if rem == word:
                    return True
                if rem[0:len(word)] == word:
                    if dp(rem[len(word):]) is True:
                        return True
            cache.append(rem)
            return False
        return dp(s)
        