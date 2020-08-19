Assignment for Lab 5:
EXERCISE 1 and 2 solved
-----------------------
EXERCISE 1: find time to read files of various sizes
exer1.h -> definition of structure,functions and some global variables
exer1.c -> definition of functions printarr and read_file
exer1_main.c -> main driver file
INPUT(implicit) -> 10,100,1000,10000,100000
OUTPUT(in output_exe1.txt) -> time taken for reading files with 10, 100 , 1,000 , 10,000 , 1,00,000 , 10,00,000 records.
TO RUN(Ubuntu) -> ./exe1
------------------------
EXERCISE 2: find time to sort(recursive insertion sort) on various sized inputs and to find stack memory used
exer2.h -> definition of functions and some global variables
exer2.c -> definition of functions insertionSort and insertInOrder
exer2_main.c -> main driver file
INPUT(implicit) -> 10,100,1000,10000,100000
OUTPUT(in output_exe2.txt) -> time taken for sorting files with 10, 100 , 1,000 , 10,000 , 1,00,000 records.
OUTPUT(in exe2_stack_size.txt) -> size on stack taken for sorting files with 10, 100 , 1,000 , 10,000 , 1,00,000 records.
OUTPUT(in final_output_exe2.txt) -> time taken and stack size used for sorting files with 10, 100 , 1,000 , 10,000 , 1,00,000 records.
TO RUN(Ubuntu) -> ./exe2 
------------------------
Graph.xlsx -> comparison between real running time vs predicted O(n^2)
------------------------
makefile -> traget for make compileAll instruction
------------------------