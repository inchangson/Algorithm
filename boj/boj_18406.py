# Q5 Answer Template

def getSum(number) :
    ret = 0
    for n in number :
        ret += int(n)
    return ret

Number = input()

sum1 = getSum(Number[:len(Number)//2])
sum2 = getSum(Number[len(Number)//2:])

if sum1 == sum2 :
    print("LUCKY")
    
else :
    print('READY')