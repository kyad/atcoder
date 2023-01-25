INF = 9**18+4;  # Please set INF >= max(n) + 1.
def int_sqrt(n):
    if n == 0:
        return 0
    left = 0
    right = INF
    while right - left > 1:
        mid = (left + right) // 2;
        y = mid * mid - n;
        if y <= 0:
            left = mid
        else:
            right = mid
    return left

# Sieve of Eratosthenes  O(N * log log (N))
M = 3*(10**6)
is_prime = [True] * (M + 1)
def eratosthenes():
  is_prime[0] = False
  is_prime[1] = False
  for k in range(2, int_sqrt(M) + 1):
      for i in range(2 * k, M + 1, k):
          is_prime[i] = False

def main():
    eratosthenes()
    primes = []
    sum = 0
    mul = 1
    for m in range(2, 32):
        if is_prime[m]:
            primes.append(m)
            sum += m;
            mul *= m
            print(m, sum, mul)
    print(primes)

if __name__ == '__main__':
    main()
