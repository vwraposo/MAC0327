x=19
mkdir 9298020-batch3
for a in 19 20 21 22 23 24 25 26 27 28 29 30;
do
    cd Aula$x
    let "x=$x+1"
    for i in A B C D E F;
    do
        if [ -f $i.cpp ];
        then
            mkdir ../9298020-batch3/9298020-A$a-P$i
            cp $i.cpp ../9298020-batch3/9298020-A$a-P$i
        fi
    done 
    cd ../
done 

