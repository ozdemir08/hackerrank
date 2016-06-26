from collections import deque
#queue that can be added and popped both sides
deq = deque()

N = int(input())

for i in range(0,N):
    line = input().split()
    if line[0] == 'append':
        deq.append(line[1])
    elif line[0] == 'pop':
        deq.pop()
    elif line[0] == 'popleft':
        deq.popleft()
    else:
        deq.appendleft(line[1])

print(' '.join(list(deq)))