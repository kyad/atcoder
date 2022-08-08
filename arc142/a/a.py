N, K = map(int, input().split())

def reverse(x):
    ans = 0
    while x > 0:
        r = x % 10
        x = x // 10
        ans = ans * 10 + r
    return ans

L = reverse(K)

if L < reverse(L):
    print(0)
    exit(0)

if K % 10 == 0:
    print(1)
    exit(0)

def solve(x):
    ans = set()
    while x <= N:
        ans.add(x)
        x *= 10
    return ans


ans1 = solve(K)
L = reverse(K)
ans2 = solve(L)
print(len(ans1 | ans2))
