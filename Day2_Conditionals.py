num1 = input("first number :")
num2 = input("second number :")
num3 = input("third number :")

n1 = float(num1)
n2 = float(num2)
n3= float(num3)

if n1==n2==n3 : 
    print("All numbers are equal")


elif n1==n3 or n1==n2 or n2 == n3 :
    print("Two number are equal")


else :

    biggest_number = max(n1,n2,n3)
    smallest_number = min(n1,n2,n3)
    print("The biggest number is :", biggest_number)
    print("The smallest number is :", smallest_number)
