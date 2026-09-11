# string is a special type of data type which behaves like container to store any type of data weather it is a number, alphabet , character , word or sentences in single or double quotes for example-:
a= "saksham"
b=' aggarwal'
print(a+b) # it dosent matter if text is in single/double quotes computer treats both of them as string
# if we want sigle/doble quotes inside our string we can use same quotes for starting and inside the string for example-:
# name="My name is "Saksham Aggarwal""
# print(name) # this will show error because we are using same type of quotes due to that python gets confused and stopped after seeing second double quote for escaping from this situation we have two ways either we use escape sequence characters or we use single quotes for example-:
Name="My name is \"Saksham Aggarwal\""
print(Name) # or we can use single quotes outside
NAME='My name is "Saksham Aggarwal"'
print(NAME)


# now if we want to print sentences in different line either use \n or which is much efficient we can use triple single/double quotes for example
laptop="""
           this laptop is apple macbook m4
           it has 256 gb ssd
           and it has 16 gb of unified ram
           """
print(laptop)