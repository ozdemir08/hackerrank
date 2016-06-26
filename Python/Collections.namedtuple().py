from collections import namedtuple
#namedtuple creates lightweight objects
N, columns = int(input()), input().split()
Student = namedtuple('Student', ','.join(columns))
sum = 0
for i in range(0, N):
    s = Student(*(input().split()))
    sum += int(s.MARKS)

print(sum / N)
