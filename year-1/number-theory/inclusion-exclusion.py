k, l, m, n = map(int, input().split())


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def lcm(a, b):
    return a / gcd(a, b) * b


A = n // k
B = n // l
C = n // m

AB = n // lcm(k, l)
BC = n // lcm(l, m)
AC = n // lcm(k, m)

ABC = n // lcm(lcm(k, l), m)

ans = A + B + C - AB - AC - BC + ABC
print(int(ans))