from collections import Counter

X, shoe_sizes, N = int(input()), list(map(int,input().split())), int(input())
counter = Counter(shoe_sizes)

gain = 0

for i in range(0,N):
    customer = list(map(int, input().split()))
    if counter.get(customer[0]) != None and counter.get(customer[0]) > 0:
        counter[customer[0]] -= 1
        gain += customer[1]

print(gain)

