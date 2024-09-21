def Int():
    return int(input())
def Ints():
    return map(int,input().split())
def IntList():
    return list(Ints())
def IntMat(N):
    return [IntList() for i in range(N)]

N,M,S = Ints()
from collections import defaultdict
Graph  = defaultdict(list)

for i in range(M):
    u,v,a,b = Ints()
    Graph[u-1].append([v-1,a,b])
    Graph[v-1].append([u-1,a,b])

City = [0]*N
for i in range(N):
    c,d = Ints()
    City[i] = [c,d]

import heapq
que = []
# [time, nowhere, money, flag, visited]
heapq.heappush(que, [0, 0, min(S,5000)])
ans = [[10**16]*5001 for i in range(N)]
#Min = [[10**16]*5001 for i in range(N+1)]
#print(Graph)
while que != []:
    time, nowhere, money = heapq.heappop(que)
    #print('here',time,nowhere,money)
    if time <= ans[nowhere][money]:
        ans[nowhere][money] = time
        c,d = City[nowhere]
        if time+d < ans[nowhere][min(5000,money+c)]:
            ans[nowhere][min(5000,money+c)] = time+d
            #print('to',time+d, nowhere, min(5000,money+c))
            heapq.heappush(que, [time+d, nowhere, min(5000,money+c)])
        for (to,a,b) in Graph[nowhere]:
            if 0 <= money - a and time+b < ans[to][min(5000,money-a)]:
                ans[to][min(5000,money-a)] = time+b
                #print('to',time+b, to, min(5000,money-a))
                heapq.heappush(que, [time+b, to, min(5000,money-a)])

for i in range(1,N):
    print(min(ans[i]))