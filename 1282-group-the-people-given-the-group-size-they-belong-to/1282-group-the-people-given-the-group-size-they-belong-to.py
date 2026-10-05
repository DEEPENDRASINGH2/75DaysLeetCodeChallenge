class Solution:
    def groupThePeople(self, groupSizes: list[int]) -> list[list[int]]:
        buckets = {}
        result = []
        for i, size in enumerate(groupSizes):
            if size not in buckets:
                buckets[size] = []
                
            buckets[size].append(i)
            if len(buckets[size]) == size:
                result.append(buckets[size])
                buckets[size] = []
                
        return result