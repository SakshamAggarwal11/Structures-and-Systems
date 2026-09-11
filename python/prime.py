def is_prime():
    num=int(input("enter the number-"))
    if(num==0 or num==1):
        return False
    else:
        for i in range(2,num):
            if num % i==0:
                return False
        return True
print(is_prime())