print("\t----Sender Side----\n")

data = input("Enter the dataword: ")

count1 = 0

for i in data:
    if i == '1':
        count1 = count1+1

if count1%2 == 1:
    data = data + '1'
else:
    data = data + '0'

print("The codeword is:  "+ data + "\n\n")

print("\t----Receiver Side----\n")

code = input("Enter the received Codeword: ")
count1 = 0

for i in code[:-1]:
    if i == '1':
        count1 = count1+1

check = 0
if count1%2 == 1:
    check = 1

if check == int(code[-1]):
    print("\n\tCorrect Message\n")
else:
    print("\n\tIncorrect Message\n")
