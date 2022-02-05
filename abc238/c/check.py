for k in range(1, 19):
    print("k=", k)
    a = 9 * (10 ** (k - 1))
    temp = a * (a + 1) // 2
    MOD = 998244353
    temp %= MOD
    print("temp=", temp)
    
