from collections import defaultdict

def ceildiv(a, b):
    return (a + b - 1) // b

INF = 10**9

def main():
    N, H = map(int, input().split())
    ds = defaultdict(lambda: -INF)  # t -> max d_t
    for n in range(N):
        t, d = map(int, input().split())
        ds[t] = max(ds[t], d)
    # Remove t and d such that t * d does not increase
    mx = -INF
    ts = []
    es = dict()
    for t in sorted(ds.keys()):
        td = t * ds[t]
        if td > mx:
            mx = td
            ts.append(t)
            es[t] = ds[t]
    # e_t --> f_t = max_t'>=t e_t'
    mx = -INF
    us = []
    for t in sorted(es.keys(), reverse=True):
        if es[t] > mx:
            us.append(t)
            mx = es[t]
    us.reverse()

    M = 0
    t = 0
    for u in us:
        f = es[u]
        s = M // f

        # sim <= s
        D = (s - t) * M
        if H <= D:
            ans = ceildiv(H, M) + t
            print(ans)
            return
        H -= D
        t = s

        # sim <= u
        def damages(x):
            return (x + t + 1) * (x - t) // 2 * f
        D = damages(u)
        if H <= D:
            left = t  # NG
            right = u  # OK
            while right - left > 1:
                mid = (left + right) // 2
                if H - damages(mid) <= 0:
                    right = mid
                else:
                    left = mid
            print(right)
            return
        H -= D
        t = u
        M = u * f
    # same as sim <= s
    ans = ceildiv(H, M) + t
    print(ans)
    return

if __name__ == "__main__":
    main()
