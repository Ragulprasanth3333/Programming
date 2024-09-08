import random
higher = int(input("Enter the Higher number:"))
lower = int(input("Enter the lower number:"))
count = 0
my_number = random.randint(lower,higher)
while True:
    count +=1
    user_number = int(input("Enter the guesed number:"))
    if user_number < my_number:
        print("Too small",user_number)
    elif user_number > my_number:
        print("Too large",user_number)
    else:
        print("The correct answer is",user_number,",",count,"tries")
        break