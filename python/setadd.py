# Enter your code here. Read input from STDIN. Print output to STDOUT

no_of_input = int(input())

s = set()

for i in range(0, no_of_input):
    s.add(input())


print(len(s))
