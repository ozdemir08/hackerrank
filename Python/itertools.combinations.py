from itertools import combinations
# combinations(A,b) returns the b combinations of A list
S, K = input().split()
K = int(K)

for a in range(1,K+1) :
    l = list(combinations(S, a))
    resultList = []
    l.sort()

    for i in l:
        s = ''
        for j in i:
            s += j
        resultList.append(''.join(sorted(s)))
    print('\n'.join(sorted(resultList)))