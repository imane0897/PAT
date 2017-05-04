import sys

for line in sys.stdin:
    a = (sum(map(int, line.split())))

    flag = 0
    count = 0
    b = []

    if a == 0:
        print(0)
        continue

    if a < 0:
        flag = 1
        a = -a

    while a > 0:
        i = a % 10
        b.insert(0, i)
        a = a // 10
        count += 1
        if count == 3 and a > 0:
            b.insert(0, ',')
            count = 0

    if flag == 1:
        b.insert(0, '-')

    c = ''.join(str(e) for e in b)
    print(c)
