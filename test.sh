x=1
time=0.1
while [ $x -le 100 ]
do
    echo "Test: $x"
    ./philosophers 4 410 200 200 7 | grep dead
    sleep $time
    x=$(( $x + 1 ))
done
