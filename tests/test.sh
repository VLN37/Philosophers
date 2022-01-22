x=1
time=0.1
echo "1 400 100 100 should die\n"
while [ $x -le 2 ]
do
	echo "Test: $x"
	./bin/philo 1 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.1
echo "2 150 360 100 25 should die\n"
echo "2 100 200 200 25 should die\n"
echo "2 150 200 100 25 should die\n"
while [ $x -le 2 ]
do
	echo "Test: $x"
	./bin/philo 2 150 360 100 25 | grep die
	./bin/philo 2 100 200 200 25 | grep die
	./bin/philo 2 150 200 100 25 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.1
echo "\n4 210 100 100 not die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	./bin/philo 4 210 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.1
echo "\n4 310 200 100 should die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	./bin/philo 4 310 200 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.1
echo "\n5 400 100 100 not die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	./bin/philo 5 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.1
echo "\n5 200 100 100 should die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	./bin/philo 5 200 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.1
echo "\n3 400 100 100 not die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	./bin/philo 3 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.1
echo "\n3 200 100 100 should die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	./bin/philo 3 200 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done
