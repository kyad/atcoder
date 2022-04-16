S = input()
A = [0] * 10
for i in range(9):
    A[ord(S[i]) - ord('0')] = 1
for i in range(10):
    if A[i] == 0:
        print(i)
