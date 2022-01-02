# class Solution:
#     def hIndex(self, citations: List[int]) -> int:
#         citations.sort(reverse=True)
#         m = len(citations)
#         ret = 0
#         for i in range(m):
#             if citations[i] > i:
#                 ret += 1
#             else:
#                 break

#         return ret

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(reverse=True)
        m = len(citations)
        ret = 0
        for i in range(m):
            if citations[i] > i:
                ret += 1
            else:
                break

        return ret