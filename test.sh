x=1
time=0.1
echo 1 400 100 100 should die
while [ $x -le 2 ]
do
	echo "Test: $x"
	./bin/philo 4 210 100 100 7 | grep died
	sleep $time
	x=$(( $x + 1 ))
done


x=1
time=0.1
echo 4 210 100 100 not die
while [ $x -le 25 ]
do
	echo "Test: $x"
	./bin/philo 4 210 100 100 7 | grep died
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.1
echo 4 310 200 100 should die
while [ $x -le 25 ]
do
	echo "Test: $x"
	./bin/philo 4 210 100 100 7 | grep died
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.1
echo 5 400 100 100 not die
while [ $x -le 25 ]
do
	echo "Test: $x"
	./bin/philo 4 210 100 100 7 | grep died
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.1
echo 5 200 100 100 should die
while [ $x -le 25 ]
do
	echo "Test: $x"
	./bin/philo 4 210 100 100 7 | grep died
	sleep $time
	x=$(( $x + 1 ))
done
