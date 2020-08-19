compRecMS: ms_sort_rec.c exer1.c
	gcc -o exe_ms_rec ms_sort_rec.c exer1.c
compIterMS: ms_sort_iter.c exer1.c
	gcc -o exe_ms_iter ms_sort_iter.c exer1.c
runRecMS: exe_ms_rec
	./exe_ms_rec
runIterMS: exe_ms_iter
	./exe_ms_iter
compare: exe_ms_iter exe_ms_rec
	./exe_ms_iter
	./exe_ms_rec

