import math as m

print("\t----Sender Side----\n")

data = input("Enter the dataword: ")

count1 = 0
lrow = m.sqrt(len(data))

if int(lrow)**2 != len(data):
    print("Not applicable for non-linear codes")
    exit()
else:
    lrow = int(lrow)

rowparity = ""

for i in range(lrow):
    count1 = 0
    for j in range(lrow):
        if data[i*lrow+j] == "1":
            count1 = count1+1
    if count1%2 == 1:
        rowparity = rowparity+"1"
    else:
        rowparity = rowparity+"0"

colparity = ""
count1 = 0

for i in range(lrow):
    count1=0
    for j in range(lrow):
        if data[j*lrow+i] == "1":
            count1 = count1+1
    if count1%2 == 1:
        colparity = colparity+"1"
    else:
        colparity = colparity+"0"

count1 = 0
for i in rowparity:
    if i == '1':
        count1 = count1+1

if count1%2 == 1:
    colparity = colparity+"1"
else:
    colparity = colparity+"0"

res = ""
for i in range(lrow):
    res += data[i*lrow:(i+1)*lrow] + rowparity[i]

res = res + colparity

print("\nCodeword is: "+ res+"\n\n")

print("\t----Receiver Side----\n")

code = input("Enter the received Codeword: ")

count1 = 0
lrow = m.sqrt(len(code))

if int(lrow)**2 != len(code):
    print("Not applicable for non-linear codes")
    exit()
else:
    lrow = int(lrow)


for i in range(lrow-1):
    count1 = 0
    for j in range(lrow):
        if code[i*lrow+j] == "1":
            count1 = count1+1
    if count1%2 == 1:
        print("\n\tIncorrect Message\n\n")
        exit()


for i in range(lrow):
    count1 = 0
    for j in range(lrow):
        if code[j*lrow+i] == "1":
            count1 = count1+1
    if count1%2 == 1:
        print("\n\tIncorrect Message\n\n")
        exit()

print("\n\tCorrect Message\n\n")
