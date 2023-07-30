N = int(input())
S = input()
a = 0
b = 0
c = 0
for n in range(N):
	if S[n] ==  'A':
		a = 1
	elif S[n] == 'B':
		b = 1
	else:
		c = 1
	if a * b * c == 1:
		print(n + 1)
		exit(0)	
