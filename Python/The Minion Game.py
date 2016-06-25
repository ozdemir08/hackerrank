vowels = {'A':1,'E':1,'I':1,'O':1,'U':1}

string = input()
N = len(string)

kevin = stuart = 0

for i in range(0, N):

    if vowels.get(string[i]) == None:
        stuart += N - i
    else:
        kevin += N - i

if stuart > kevin:
    print('Stuart', stuart)
elif stuart < kevin:
    print('Kevin', kevin)
else:
    print('Draw')


