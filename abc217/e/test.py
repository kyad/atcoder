print(2 * 10 ** 5)
for q in range(2 * 10 ** 5):
    if q % 5 < 3:
        print(1, q)
    elif q % 5 < 4:
        print(2)
    else:
        print(3)
