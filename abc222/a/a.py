N = input()
l = len(N)
if l == 1:
    ans = "000" + N;
elif l == 2:
    ans = "00" + N;
elif l == 3:
    ans = "0" + N;
else:
    ans = N;
print(ans)
