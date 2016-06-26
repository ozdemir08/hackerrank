from itertools import product
# cartesian product
# * list'ten parantezi kaldiriyor

#print (list(product([1,2,3],repeat = 3)))
# print (list(product([1,2,3],[3,4])))
# A = [[1,2,3],[3,4,5],[6,7,8]]
# print (list(product(*A)))
# print(*A)

print( *list(product(list(map(int,input().split())), list(map(int, input().split())))))

