A, B, C = map(int, input().split())
if A <= B <= C or C <= B <= A:
    print('Yes')
else:
    print('No')
