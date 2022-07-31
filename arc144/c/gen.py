for N in range(2, 8):
    for K in range(1, N):
        fname = 'test/N{}_K{}.in'.format(N, K)
        with open(fname, 'w') as f:
            f.write('{} {}\n'.format(N, K))
