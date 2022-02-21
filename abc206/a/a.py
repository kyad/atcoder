# https://atcoder.jp/contests/abc206/tasks/abc206_a

N = int(input())
a = int(N * 1.08)
if a < 206:
    ans = 'Yay!'
elif a == 206:
    ans = 'so-so'
else:
    ans = ':('
print(ans)
