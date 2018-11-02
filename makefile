all:
	g++ src/main.cpp -o main
run:
	./main < input.txt > mi_output.txt
runsmall:
	./main < validation/small_in.txt > mi_output.txt
runbig:
	./main < validation/in.txt > mi_output.txt
