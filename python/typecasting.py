# TYPECASTING
# Conversion of one data type to another data type is called as typecasting.IN python it can be done by varity of functions like int,float,str,ord,hex,oct,tuple,list,dict etc
# There are two type of typecasting-: a) explicit          b)implicit
# Explicit typecasting-: it is forcefully conversion of one data type to another by the user itself 
a="10"
b="10"
print(a+b)           # output will be 1010
print(int(a)+int(b)) # now this is typecasting converting string to integer and output will be 20
# Implicit typecasting-: it is conversion of one data type to another by python itself , python converts lower level of data type to higher oder data type
c=1.324
d=93
print(c+d) # now after addition of float and integer answer will come in float which is 94.324