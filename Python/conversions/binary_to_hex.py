"""This code converts a binary value to its hexadecimal equivalent. Here,we have used the while loop.  To convert binary to hexadecimal number, you have to ask from user to enter a number in binary number system to convert that number into hexadecimal number system """

print("Enter the Binary Number: ")
bnum = int(input())

hex = 0
mul = 1
chk = 1
# counter for hexadecimal number array
i = 0
hnum = []
while bnum!=0:
    rem = bnum%10
    hex = hex + (rem*mul)
# check if group of 4 completed    
    if chk%4==0:
        # check if hex < 10
        if hex<10:
            hex = hex+48
            val = chr(hex)
            hnum.insert(i, val)
 # group of 4 is not completed           
        else:
            hex = hex+55
            val = chr(hex)
            hnum.insert(i, val)
        mul = 1
        hex = 0
        chk = 1
        i = i+1
    else:
        mul = mul*2
        chk = chk+1
    bnum = int(bnum/10)
# check if at end the group of 4 is not completed
if chk!=1:
    hex = hex+48
    val = chr(hex)
    hnum.insert(i, val)
# check at end the group of 4 is completed
if chk==1:
    i = i-1
# printing hexadecimal number
print("\nEquivalent Hexadecimal Value = ", end="")
while i>=0:
    print(end=hnum[i])
    i = i-1
print()
