import sys
# sys.stdin = open("input.txt", "r")


def go(x):
    if x == 1:
        return matrix[:]
    else:
        tmp = go(x // 2)
        res = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    res[i][j] += tmp[i][k] * tmp[k][j] % 1000
        if x % 2 == 1:
            tmp2 = [[0 for _ in range(n)] for _ in range(n)]
            for i in range(n):
                for j in range(n):
                    for k in range(n):
                        tmp2[i][j] += res[i][k] * matrix[k][j] % 1000
            return tmp2
        else:
            return res


n, b = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(n)]
for i in range(n):
    for j in range(n):
        matrix[i][j] = matrix[i][j] % 1000

answer = go(b)
for i in range(n):
    for j in range(n):
        print(answer[i][j], end=' ')
    print()
