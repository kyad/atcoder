def is_same(S, T):
    if len(S) != len(T):
        return False
    if len(S[0]) != len(T[0]):
        return False
    for y in range(len(S)):
        if S[y] != T[y]:
            return False
    return True

def minimize(S):
    # left
    left = 0
    done = False
    for x in range(N):
        for y in range(N):
            if S[y][x] == '#':
                left = x
                done = True
                break
        if done:
            break
    # right
    right = N - 1
    done = False
    for x in range(N - 1, -1, -1):
        for y in range(N):
            if S[y][x] == '#':
                right = x
                done = True
                break
        if done:
            break
    # top
    top = 0
    done = False
    for y in range(N):
        for x in range(N):
            if S[y][x] == '#':
                top = y
                done = True
                break
        if done:
            break
    # bottom
    bottom = 0
    done = False
    for y in range(N - 1, -1, -1):
        for x in range(N):
            if S[y][x] == '#':
                bottom = y
                done = True
                break
        if done:
            break
    h = bottom - top + 1
    new_S = []
    for y in range(h):
        new_S.append(S[top + y][left:right+1])
    return new_S

def rotate(S):
    w = len(S[0])
    h = len(S)
    new_h = w
    new_w = h
    new_S = []
    for y in range(new_h):
        temp = ''
        for x in range(new_w):
            temp += S[x][new_h - 1 - y]
        new_S.append(temp)
    return new_S

N = int(input())
S = []
for n in range(N):
    S.append(input())
T = []
for n in range(N):
    T.append(input())

S = minimize(S)
T = minimize(T)
if is_same(S, T):
    print("Yes")
    exit(0)
for i in range(3):
    S = rotate(S)
    if is_same(S, T):
        print("Yes")
        exit(0)
print("No")
