import math

def nok(a1, b1):
  return a1*b1 / math.gcd(a1, b1) 

n = int(input())
a = n//2
b = n - a
print(a, b)
n = int(nok(a , b))
if n <= a:
    print(int(nok(a , b)))
else:
    a+=1
    b-=1
    print(a, b)
    print(int(nok(a , b)))