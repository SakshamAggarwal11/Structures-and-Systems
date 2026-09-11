a=input("enter the value of a-:")
match a:
    case "help":
        print("goodmorning")
    case 2:
        print("goodevening")
    case 3:
        print("goodnight")
    case _ if a!=4:
        print("not found")
    case _:
        print("invalid")