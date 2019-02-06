def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)

def lcm(a,b):
    return (a*b)/gcd(a,b)

T = int(input())
while T:
    N, A, B, K = [int(x) for x in input().strip().split(" ")]
    
    a_s = N // A
    c_s = N // B
    b_s = N // lcm(A, B)

    if (a_s - 2*b_s + c_s) >= K:
        print("Win") 
    else:
        print("Lose")

    T = T - 1