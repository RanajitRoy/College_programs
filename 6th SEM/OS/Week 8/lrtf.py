n = int(input("No. of Processes: "))

at = input("Enter arrival times: ")
at = [int(x) for x in at.split()]

bt = input("Enter burst times: ")
bt = [int(x) for x in bt.split()]

ct = [0]*n

def find_max(time):
    max_pid = -1
    max_bt = -1
    for i in range(n):
        if bt[i] > max_bt and at[i] <= time:
            max_pid = i
            max_bt = bt[i]
    return max_pid

loop = sum(at) + sum(bt) + 1

for i in range(loop):
    now = find_max(i)
    if bt[now] > 0 and now >= 0:
        bt[now] = bt[now] - 1
        if bt[now] == 0:
            ct[now] = i+1

avg_tat = 0
print("\nProcess\tTAT")
for i in range(n):
    print("p"+str(i),"\t"+str(ct[i]-at[i]))
    avg_tat += ct[i] - at[i]

print("\nAverage Turn Around Time =",avg_tat/n)
