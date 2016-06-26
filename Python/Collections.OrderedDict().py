from collections import OrderedDict

N = int(input())

ordered_dict = OrderedDict()

for i in range(0, N):
    line = input().split()
    net_price = int(line[-1])
    item_name = ' '.join(line[0:len(line)-1])
    if ordered_dict.get(item_name) == None:
        ordered_dict[item_name] = net_price
    else:
        ordered_dict[item_name] += net_price

for word in ordered_dict:
    print(word,' ', ordered_dict[word])
