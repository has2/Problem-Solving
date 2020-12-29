#!/bin/sh
echo -e "LEVEL : \c"
read LEVEL

echo -e "문제번호 : \c"
read NUM

echo -e "문제이름 : \c"
read NAME

echo -e "유형 : \c"
read TYPE

# LEVEL=$1
# NUM=$2
# NAME=$3
# TYPE=$4
DATE=$(date +%Y%m%d)

echo "LEVEL:${LEVEL}, NUM:${NUM}, NAME:${NAME}, TYPE:${TYPE}"

echo "\
[${DATE}] ${TYPE}

[BOJ/백준][${LEVEL}] ${NUM} : ${NAME} (C++) 

https://www.acmicpc.net/problem/${NUM}





[난이도] ${LEVEL} 
[유형] ${TYPE} 

[풀이] 



https://github.com/has2/Problem-Solving/blob/master/boj-solved.ac/${LEVEL}/${NUM}.cpp \
" > ../.gitmessage.txt
git add ../.
git commit