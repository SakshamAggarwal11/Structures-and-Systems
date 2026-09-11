def fibonachi(n):
    if n==0 or n==1:
        return n
    fibo_l=[0,1]
    for i in range(2,n):
        fibo=fibo_l[-1]+fibo_l[-2]
        fibo_l.append(fibo)
    return fibo_l
print(fibonachi(5))