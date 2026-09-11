def unique():
    old_l=[]
    new_l=[]
    n=int(input("enter how many numbers you want to enter in the list-"))
    print("enter the numbers in list-")
    for i in range(n):
       num=int(input(""))
       old_l.append(num)
    for i in old_l:
        if(old_l.count(i)==0):
            num=i
            new_l.append(num)
        else:
            if(new_l.count(i)==0):
                num=i
                new_l.append(num)
            # else:
            #     pass       
    return new_l
print(type(unique()))