from collections import Counter
from operator import itemgetter


def cmp(a, b):
    if counter[a] > counter[b]:
        return -1
    if counter[a] < counter[b]:
        return 1
    if a < b:
        return -1
    return 1

counter = Counter(input())

print(sorted(counter, key=str.lower))

# for t in most_commons:
#     print(t[0],t[1])

