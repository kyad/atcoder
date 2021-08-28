a = []
a.append(input())
a.append(input())
a.append(input())
a.append(input())
b = [0] * 4
for i in range(4):
    if a[i] == 'H':
        b[0] = 1
    elif a[i] == '2B':
        b[1] = 1
    elif a[i] == '3B':
        b[2] = 1
    elif a[i] == 'HR':
        b[3] = 1
for i in range(4):
    if b[i] == 0:
        print('No')
        exit(0)
print('Yes')

          
           
    
