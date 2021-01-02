#!/bin/sh

BOJ='BOJ/백준'
CF='Codeforces'
echo -e "플랫폼 선택 (1)=boj, (2)=codeforces : \c"
read PLATFORM
if [ ${PLATFORM} -eq 1 ]; then
    PLATFORM=${BOJ}
elif [ ${PLATFORM} -eq 2 ]; then
    PLATFORM=${CF}
else
    echo "1과 2중 선택해주세요"
    exit 1  
fi

if [ ${PLATFORM} == ${BOJ} ];then
    echo -e "LEVEL : \c"
    read LEVEL

    echo -e "문제번호 : \c"
    read NUM

    echo -e "문제이름 : \c"
    read NAME

    echo -e "유형 : \c"
    read TYPE

    TITLE="[${PLATFORM}][${LEVEL}] ${NUM} : ${NAME} (C++)"
    LINK="https://www.acmicpc.net/problem/${NUM}"
    GITLINK="https://github.com/has2/Problem-Solving/blob/master/boj-solved.ac/${LEVEL}/${NUM}.cpp"

    echo "PLATFORM:${PLATFORM}, LEVEL:${LEVEL}, NUM:${NUM}, NAME:${NAME}, TYPE:${TYPE}"
    cp ../solving.cpp ../boj-solved.ac/${LEVEL}/${NUM}.cpp
else
    echo -e "ROUND : \c"
    read ROUND

    echo -e "DIVISION : \c"
    read DIV
    LEVEL=Div.${DIV}

    echo -e "문제 알파벳(A,B,C,D...) : \c"
    read ALPHA
    ALPHA=${ALPHA^}

    echo -e "문제이름 : \c"
    read NAME

    echo -e "유형 : \c"
    read TYPE

    echo -e "링크 : \c"
    read LINK
 
    TITLE="[${PLATFORM}][Round #${ROUND}][Div.${DIV}] ${ALPHA} : ${NAME} (C++)"

    DIRNAME=codeforces/Round${ROUND}-Div.${DIV}
    GITLINK="https://github.com/has2/Problem-Solving/blob/master/${DIRNAME}/${ALPHA}.cpp"


    echo "PLATFORM:${PLATFORM}, ROUND:${ROUND}, DIVISION:${DIV}, ALPHA:${ALPHA}, NAME:${NAME}, TYPE:${TYPE}"
    
    
    if [ ! -d ../${DIRNAME} ]; then
        echo "Directoy ../${DIRNAME} is not exist.. create DIR"
        mkdir ../${DIRNAME}
    fi
    cp ../solving.cpp ../${DIRNAME}/${ALPHA}.cpp
fi

DATE=$(date +%Y%m%d)




echo ${TITLE}
echo ${LINK}

echo "\
[${DATE}] ${TYPE}

${TITLE}

${LINK}




[난이도] ${LEVEL} 
[유형] ${TYPE} 

[풀이] 




${GITLINK} \
" > ../.gitmessage.txt
git add ../.
git commit