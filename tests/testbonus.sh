x=1
time=0.1
echo "1 400 100 100 should die\n"
while [ $x -le 2 ]
do
	echo "Test: $x"
	./bin/philo_bonus 1 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done


x=1
time=0.1
echo "\n4 210 100 100 not die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	./bin/philo_bonus 4 210 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.1
echo "\n4 310 200 100 should die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	./bin/philo_bonus 4 310 200 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.1
echo "\n5 400 100 100 not die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	./bin/philo_bonus 5 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.1
echo "\n5 200 100 100 should die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	./bin/philo_bonus 5 200 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.1
echo "\n3 400 100 100 not die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	./bin/philo_bonus 3 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

x=1
time=0.1
echo "\n3 200 100 100 should die\n"
while [ $x -le 25 ]
do
	echo "Test: $x"
	./bin/philo_bonus 3 200 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done
