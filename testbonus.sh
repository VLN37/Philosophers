x=1
time=0.1
while [ $x -le 100 ]
do
    echo "Test: $x"
    ./philosophers_bonus 5 800 200 200 7 | grep dead
    sleep $time
    x=$(( $x + 1 ))
done