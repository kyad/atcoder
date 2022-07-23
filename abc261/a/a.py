L1, R1, L2, R2 = map(int, input().split())
l = max(L1, L2)
r = min(R1, R2)
if l < r:
   print(r - l)
else:
   print(0)

