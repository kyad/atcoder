X, Y = map(int, input().split('.'))
if 0 <= Y <= 2:
    print('{}-'.format(X))
elif 3 <= Y <= 6:
    print('{}'.format(X))
elif 7 <= Y <= 9:
    print('{}+'.format(X))
