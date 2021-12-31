x=1
time=0.1
while [ $x -le 100 ]
do
	echo "Test: $x"
	./bin/philo 4 210 100 100 7 | grep died
	sleep $time
	x=$(( $x + 1 ))
done
