{\rtf1\ansi\deff0\nouicompat{\fonttbl{\f0\fnil\fcharset129 \'b8\'bc\'c0\'ba \'b0\'ed\'b5\'f1;}}
{\*\generator Riched20 10.0.14393}\viewkind4\uc1 
\pard\sa200\sl276\slmult1\f0\fs20\lang18 import math\par
\par
n, k = map(int, input().split())\par
l = [ [0 for j in range(7)] for i in range(2)]\par
for i in range(n):\par
    s,y = map(int, input().split())\par
    l[s][y]+=1\par
\par
cnt = 0\par
h = [0,0,0,0,0]\par
for i in range(0,2):\par
    for j in range(1,7):\par
        if j<3:\par
            h[0]+=l[i][j]\par
        elif j>2 and j<5:\par
            if i==0:\par
                h[1]+=l[i][j]\par
            else:\par
                h[2]+=l[i][j]\par
        else:\par
            if i==0:\par
                h[3]+=l[i][j]\par
            else:\par
                h[4]+=l[i][j]\par
\par
for i in range(5):\par
    cnt+=math.ceil(h[i]/k)\par
\par
print(cnt)\par
}
 