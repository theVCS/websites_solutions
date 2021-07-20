import math

n = int(input())
BST = []
UNI = []
for i in range(0,n):
    line = input()
    li = line.split()
    if len(li)==3:
        data = {
            "user":li[0],
            "x":float(li[1]),
            "y":float(li[2]),
        }
    BST.append(data)
m = int(input())
for i in range(0,m):
    line = input()
    li = line.split()
    if len(li)==3:
        data = {
            "user":li[0],
            "x":float(li[1]),
            "y":float(li[2]),
        }
        UNI.append(data)


def FINDIS(i,j):
    return math.sqrt((i["x"]-j["x"])*(i["x"]-j["x"]) + (i["y"]-j["y"])*(i["y"]-j["y"]))
def FINDD(j):
    lowest = FINDIS(j,BST[0])
    point = {}
    for i in BST:
        dist = FINDIS(i,j)
        if dist < lowest and not i==j:
            lowest = dist
            point = i 
    return point
final = []
for i in UNI:
    
    try:
        point_q = FINDD(i)
        if point_q != {}:
            point_r = FINDD(point_q)
            if FINDIS(point_q,point_r) !=0:
                if FINDIS(i,point_q)/FINDIS(point_q,point_r)<1:
                    final.append(i["user"])
    except:
        continue
final.sort()
for i in final:
    print(i)
