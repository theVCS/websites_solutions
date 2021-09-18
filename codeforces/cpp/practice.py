def checker(str):
    for ch in str:
        if((ch>='A' and ch <= 'Z') or (ch >='a' and ch<='z') or ch == '-' or ch==',' or ch=='!' or ch=='.' or ch=='?'):
            continue
        else:
            return False
    
    return True

def howMany(sentence):
    x = sentence.split()
    cnt = 0
    for str in x:
        if(checker(str)):
            cnt=cnt+1
    return cnt


str = input()
print(howMany(str))