N,X = list(map(int, input().split()))

arr = []
[arr.append(list(map(float,input().split()))) for j in range(0,X)]

[print(sum(i)/X) for i in list(zip(*arr))]
