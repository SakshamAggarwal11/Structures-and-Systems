#  write a program that wishes good morning good afternoon and good night acording to time
time=int(input("enter only hour in 24 hour format-:"))
if(time<4 or time>=18):
    print('goodnight user')
elif(time>=4 and time<12):
    print('goodmorning user')
elif(time>=12 and time<18):
    print('goodevening user')
else:
    print('invlid time')