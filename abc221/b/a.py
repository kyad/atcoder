S = input()
T = input()
if S == T:
    print("Yes")
    exit(0)
ans = "No"
for i in range(len(S) - 1):
    temp = ""
    for j in range(len(S)):
        if j == i:
            temp = temp + S[i + 1]
        elif j == i + 1:
            temp = temp + S[i]
        else:
            temp = temp + S[j]
    if temp == T:
        ans = "Yes"
        break
print(ans)
