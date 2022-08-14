import sys

# Read test data
fname = sys.argv[1]
with open(fname) as f:
    N = int(f.readline().strip())
    D = [0] * N
    for n in range(N):
        D[n] = list(map(int, f.readline().strip().split()))
ans = D[0][1]

# Interactive
print(N)
while True:
    S = input()
    #print("judge S={}".format(S), file=sys.stderr)
    if S[0] == '?':
        _, u, v = S.split()
        u = int(u)
        v = int(v);
        if (u + v <= 3):
            print(-1)
            exit(1)
        print(D[u - 1][v - 1])
    else:
        _, d = S.split()
        d = int(d)
        if d == ans:
            print("judge AC", file=sys.stderr)
            exit(0)
        else:
            print("judge WA d=", d, file=sys.stderr)
            exit(1)
