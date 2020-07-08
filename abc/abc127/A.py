a, b = map(int,input().split())

def main(_old, _fee):
    if int(_old) >= 13:
        return int(_fee)
    elif 6 <= int(_old) <= 12:
        return int(_fee) // 2
    else:
        return 0

if __name__ == '__main__':
    print(main(a, b))
