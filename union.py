# Enter your code here. Read input from STDIN. Print output to STDOUT
 
# eng_no = int(input())
# eng_set = set()

# eng_set.add(map(str,input().split()))

# frnch_no = int(input())

# frnch_set = set()

# frnch_set.add(map(str,input().split()))

# print(eng_no.union(frnch_set))

# a = input(), set(input().split())
# b = input(), set(input().split())
# print(len(a.union(b)))
n = input()
set_n = set(map(int, input().split()))
b = input()
set_b = set(map(int, input().split()))
print(len(set_n.union(set_b)))
