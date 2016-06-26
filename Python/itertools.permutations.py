from itertools import permutations
#permutations(S) returns the permutations of S list
S, K  = input().split()
list = list(permutations(S, int(K)))
list.sort()

for i in list:
    s = ''
    for j in i:
        s += j
    print(s)