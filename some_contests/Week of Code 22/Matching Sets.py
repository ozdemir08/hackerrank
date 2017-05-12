n = int(input())

X = [int(a_temp) for a_temp in input().split()]
Y = [int(a_temp) for a_temp in input().split()]

if ( sum(X) != sum(Y)):
    print(-1)
else:
    X = sorted(X)
    Y = sorted(Y)
    sum = 0
    for i in range(0,n):
        sum += abs(X[i] - Y[i])

    print(int(sum/2))
