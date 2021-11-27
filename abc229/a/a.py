S = []
S.append(input())
S.append(input())
count = [0] * 2
for i in range(2):
    for j in range(2):
        if S[i][j] == "#":
            count[i] += 1
if count[0] == 1 and count[1] == 1:
    if S[0][0] == "#":
        if S[1][1] == "#":
            ans = "No"
        else:
            ans = "Yes"
    else:  # S[0][1] == "#":
        if S[1][0] == "#":
            ans = "No"
        else:
            ans = "Yes"
else:
    ans = "Yes"
print(ans)
