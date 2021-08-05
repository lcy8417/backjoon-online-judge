import sys
sys.stdin = open("input.txt", "r")


def go(x, e):
    if e == 1:
        return x % c
    else:
        tmp = go(x, e // 2)
        if e % 2 == 0:
            return tmp * tmp % c
        else:
            return tmp * tmp * a % c


a, b, c = map(int, input().split())
print(go(a, b))
