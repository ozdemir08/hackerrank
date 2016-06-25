from itertools import permutations

S, K  = input().split()
list = list(permutations(S, int(K)))
list.sort()

for i in list:
    s = ''
    for j in i:
        s += j
    print(s)