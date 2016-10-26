x, k = input().split()
polynomial = input()

if int(k) == eval(polynomial.replace('x', x)):
    print('True')
else:
    print('False')
