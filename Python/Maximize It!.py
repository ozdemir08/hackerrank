from itertools import product

(N, K) = map(int,input().split())
lists = []

for i in range(0,N):
    k = list(map(int, input().split()))
    lists.append(k[1:])

cartesian_products = list(product(*lists))
result = 0

for i in cartesian_products:
    sum = 0
    for j in i:
        sum += j*j
    result = max(result, sum%K)

print(result)
