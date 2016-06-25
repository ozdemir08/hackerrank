from collections import defaultdict

d = defaultdict(list)
(N, M) = tuple(map(int,input().split()))

for i in range(1,N+1):
    x = input()
    d[x].append(i)

for i in range(1,M+1):
    x = input()
    if d.get(x) != None:
        print(' '.join(map(str,d[x])))
    else:
        print(-1)