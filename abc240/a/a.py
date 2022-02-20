A, B = map(int, input().split())
temp = (A - B + 10) % 10
if temp == 1 or temp == 9:
    ans = "Yes"
else:
    ans = "No"
print(ans)
