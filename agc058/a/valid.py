def valid(id):
    with open('test/{}.in'.format(id)) as f:
        N = int(f.readline().strip())
        P = list(map(int, f.readline().strip().split()))
    with open('test/{}.txt'.format(id)) as f:
        K = int(f.readline().strip())
        X = list(map(int, f.readline().strip().split()))
    if K > N:
        print("Error id={} K={}".format(id, K))
        return
    if K != len(X):
        print("Error")
        return
    for x in X:
        x -= 1
        P[x], P[x + 1] = P[x + 1], P[x]
    # check
    for x in range(0, 2 * N - 1, 2):
        if (P[x] > P[x + 1]):
            print("Error id={} x={} P={}".format(id, x, P))
            return
    for x in range(1, 2 * N - 1, 2):
        if (P[x] < P[x + 1]):
            print("Error id={} x={} P={}".format(id, x, P))
            return

for i in range(100):
    id = 'random-{:03d}'.format(i)
    valid(id)
