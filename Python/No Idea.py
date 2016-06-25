N, M = map(int, input().split())

A = input().split()

likes = input().split()
dislikes = input().split()

happiness = 0

likesDislikes = [];
for i in likes:
    likesDislikes.append((i, 1))
for i in dislikes:
    likesDislikes.append((i, -1))

likesDislikes.sort()
A.sort()
place = 0

for i in likesDislikes:
    while place < len(A) and A[place] <= i[0]:
        if i[0] == A[place]:
            happiness += i[1]
        place += 1

print(happiness)
