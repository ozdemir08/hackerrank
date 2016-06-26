from itertools import groupby
#groupby string'deki yanyana olan elemanlari grupluyor.
for i in groupby(input()):
    print((len(list(map(int,i[1]))),int(i[0])), end=' ')
