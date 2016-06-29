from collections import Counter
#.items -> elements in tuple format
# key=lambda x: (-x[1], x[0]))[0:3] sort in ascending order according to second one and descending order acc. to first one
[print(x[0], x[1]) for x in sorted(Counter(input()).items(), key=lambda x: (-x[1], x[0]))[0:3]]

# for t in most_commons:
#     print(t[0],t[1])

