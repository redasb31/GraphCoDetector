try:
    S = list(input())
    T = list(input())
    t = len(T)
    candidate = []
    for i in range(len(S)):
        tmp = S[i:i+t]
        for j in range(len(tmp)):
            if tmp[j] == T[j] or '?' == tmp[j]:
                pass
            else:
                break
        else:
            candidate.append(S[0:i]+T+S[i+t:len(S)])
    for i in range(len(candidate)):
        l = list(candidate[i])
        for j in range(len(l)):
            if l[j] == '?':
                l[j] = 'a'
        candidate[i]=l
    candidate = list(filter(lambda x:len(x)==len(S),candidate))
    candidate.sort()
    for x in candidate[0]:
        print(x,end='')
    print()
except:
    print("UNRESTORABLE")