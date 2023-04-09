
ls=list()

while True:
    s=input()
    if s:
        ls.append(s.upper())
    else:
        break

for s in ls:
    print(s)
