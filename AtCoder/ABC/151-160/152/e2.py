from fractions import gcd

def lcm(x, y):
    return x / gcd(x, y) * y

n = int(input())
a = [int(x) for x in input().split()]

v = 1
for x in a:
    v = lcm(v, x)

sum = 0
for x in a:
    sum += v / x

print(int(sum % 1000000007))