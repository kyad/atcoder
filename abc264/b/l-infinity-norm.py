R, C = map(int, input().split())
print('white' if max(abs(R - 8), abs(C - 8)) % 2 == 0 else 'black')
