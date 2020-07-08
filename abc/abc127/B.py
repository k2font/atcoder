# 再帰っぽく書くにはどうする？

a, b, c = map(int,input().split())
r = a
d = b
x_init = c
result = []

def main(_r, _d, _x, _i):
    result.append(int(_r) * int(_x) - int(_d))
    return result[_i]

for i in range(10):
    if i == 0:
        main(r, d, x_init, i)
    else:
        main(r, d, result[i - 1], i)
    print(result[i])
