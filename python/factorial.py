def factorial():
    fact=1
    num=int(input("enter no to calculate factorial-"))
    for i in range(1,num+1):
        fact=fact*i
    return fact
print(factorial())