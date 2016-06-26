from collections import deque

T = int(input())

for i in range(0,T):
    n = int(input())
    last_number = 2
    result = 'Yes'
    deq = deque(list(map(int,input().split())))
    while len(deq) > 0:
        if deq[0] >= deq[-1] and deq[0] <= last_number:
            last_number = deq[0]
            deq.popleft()
        elif deq[0] <= deq[-1] and deq[-1] <= last_number:
            last_number = deq[-1]
            deq.pop()
        else:
            result = 'No'
            break

    print(result)



