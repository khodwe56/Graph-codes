from collections import *
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        inF,outF = defaultdict(set),defaultdict(set)
        res = []
        q = deque()
        for i,j in prerequisites:
            inF[i].add(j)
            outF[j].add(i)
        for i in range(numCourses):
            if i not in inF:
                q.append(i)
        while q:
            p = q.popleft()
            res.append(p)
            if p in outF:
                for course in outF[p]:
                    inF[course].discard(p)
                    if not inF[course]:
                        q.append(course)
                del outF[p]

        if outF:
            return []
        return res
