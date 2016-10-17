x=11
mkdir 9298020-batch2
for a in 11 12 13 14 15 16 17 18;
do
    cd Aula$x
    let "x=$x+1"
    for i in A B C D E F;
    do
        if [ -f $i.cpp ];
        then
            mkdir ../9298020-batch2/9298020-A$a-P$i
            cp $i.cpp ../9298020-batch2/9298020-A$a-P$i
        fi
    done 
    cd ../
done 

