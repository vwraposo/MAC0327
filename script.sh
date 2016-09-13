x=1
for a in 01 02 03 04 05 06 07 08 09 10;
do
    cd Aula$x
    let "x=$x+1"
    for i in A B C D E F;
    do
        if [ -f $i.cpp ];
        then
            mkdir ../9298020-batch1/9298020-A$a-P$i
            cp $i.cpp ../9298020-batch1/9298020-A$a-P$i
        fi
    done 
    cd ../
done 

