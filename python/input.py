# In python we can take input from user by the help of input() fuction 
# Importent thing is in python every data taken by the input function is stored as string data type
a=input("enter first number-:")
b=input("enter second number-:")
print("the value of a","+","b is-:",a+b) # output will come wrong because 'a' and 'b' is string we have to typecaste them before adding
print("the value of a","+","b is-:",int(a)+float(b)) # here python will convert entire output to float which is implicit typecasting
print("the value of a","-","b is-:",int(a)-float(b))
print("the value of a","*","b is-:",int(a)*float(b))
print("the value of a","/","b is-:",int(a)/float(b))
print("the value of a","//","b is-:",int(a)//float(b))
print("the value of a","%","b is-:",int(a)%float(b))