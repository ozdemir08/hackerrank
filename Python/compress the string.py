from itertools import groupby

for i in groupby(input()):
    print((len(list(map(int,i[1]))),int(i[0])), end=' ')
