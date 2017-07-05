#!/bin/bash  


split() {
    user='mark:x:0:0:this is a test user:/var/mark:nologin'
    user=$1  #待分割的字符串
    delim=$2 #分隔符
	     #$2 第几个	
    i=0  
    while [ "$i" -le $3 ]
    do  
        i=$((i + 1))  
        spli=`echo $user|cut -d $delim -f ${3}`  
        if [ "$spli" != "" -a "$i" = "$3"  ]  
        then  
                echo $spli  
        fi  
    done 
}



#============ get the file name ===========  
Folder_A="/home/zhoutengteng/Documents/softwareCodeForHuaWei"  
Output_file="output.txt"  
#这里用于清空原本的输出文件，感觉 : 这个符号用处挺大，shell的学习还是要多用才是  
: > $Output_file                                                                                                                                            
`git pull origin master`
for file_a in ${Folder_A}/*; do  
    value=`echo $file_a | awk  -F '/' '/cpp|py/{print $6}'`
    if [ "$value" = "" ]
    then
        continue
    fi
    #temp_file=`basename $file_a`  
    #file_a=`echo $file_a | cut -d  
    value_value=`split "$value" "-" "2"`
    value_key=`split "$value" "-" "1"`
    if [ ! -n  "$(echo $value_key | sed -n "/^[0-9]\+$/p")" ]
    then
        continue
    fi
    
    echo $value,$value_key,$value_value 
    `git add ${value}`
    `git commit -m ${value_value}`
done 
`git push origin master`
