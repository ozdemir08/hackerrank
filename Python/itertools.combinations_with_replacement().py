from itertools import combinations_with_replacement

S, K = input().split()

list = []
[list.append(''.join(sorted(i))) for i in combinations_with_replacement(S,int(K))]

print('\n'.join(sorted(list)))