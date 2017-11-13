compilador = gcc
arquivoFonte = trab-comp2
executavel = trab

all:
	$(compilador) -c $(arquivoFonte).c
	$(compilador) $(arquivoFonte).o -lm -o $(executavel)
run:
	./$(executavel)
clean:
	rm *.o
	rm $(executavel)
	reset
