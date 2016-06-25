import math
N , letters, K = int(input()), input().split(), int(input())


def comb(N,K):
    return math.factorial(N) / math.factorial(K) / math.factorial(N-K)

x = letters.count('a')
print(1 - comb(N-x,K)/comb(N,K))

