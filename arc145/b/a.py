N, A, B = map(int, input().split())

if N < A:
    print(0)
elif A <= B:
    ans =  N - A + 1
    print(ans)
else:
    round = (N - (A - 1)) // A
    per1 = B - 1 + 1
    ans = round * per1
    if (((N - (A - 1)) % A) > 0):
        per1 = B - 1 + 1
        count = (N - (A - 1)) % A;
        now = min(count, per1);
        ans += now;
    print(ans)
    
