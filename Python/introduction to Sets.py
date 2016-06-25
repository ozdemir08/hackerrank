N = int(input())
s = set(input().split())

sum = 0
for i in s:
    sum += int(i)

print(sum / len(s))
