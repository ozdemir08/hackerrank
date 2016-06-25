from itertools import combinations

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