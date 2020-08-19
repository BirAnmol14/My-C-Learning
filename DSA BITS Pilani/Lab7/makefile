compMain: main.c quick_sort.c insertion_sort.c sort.c stack.c extras.c
	gcc -o exe_main main.c quick_sort.c insertion_sort.c sort.c  stack.c extras.c
runMain: exe_main exe_test
	./exe_test 10
	./exe_main 10 10_Summary_out
	./exe_test 100
	./exe_main 100 100_Summary_out
	./exe_test 1000
	./exe_main 1000 1000_Summary_out
	./exe_test 10000
	./exe_main 10000 10000_Summary_out
	./exe_test 100000
	./exe_main 100000 100000_Summary_out
compTest: test.c quick_sort.c insertion_sort.c sort.c stack.c extras.c
	gcc -o exe_test test.c quick_sort.c insertion_sort.c sort.c  stack.c extras.c
runTest: exe_test
	./exe_test 10 100 1000 10000 100000 

