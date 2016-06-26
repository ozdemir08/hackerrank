from collections import OrderedDict

ordered_dict = OrderedDict()

N = int(input())
for i in range(0,N):
    word = input()
    if ordered_dict.get(word) == None:
        ordered_dict[word] = 1
    else:
        ordered_dict[word] += 1

print(len(ordered_dict))

for word in ordered_dict:
    print(ordered_dict[word], end=' ')