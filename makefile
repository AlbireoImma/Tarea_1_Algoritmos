all:
	g++ src/main.cpp -o main -Wall
run:
	./main < input.txt
runsmall:
	./main < validation/small_in.txt > mi_output.txt
runbig:
	./main < validation/in.txt > mi_output.txt
diffsmall:
	diff  mi_output.txt validation/small_out.txt -u
diffbig:
	diff  mi_output.txt validation/out.txt -u