#Make File Para utilização no Trabalho de ED 1
compilador = gcc
arquivoFonte = lista
arquivoFonte1 = prog
executavel = progf
arquivoFinal = progf
#comando para criação do programa linkando os arquivos objeto do #TAD
all:
	$(compilador) -c $(arquivoFonte).c
	$(compilador) -c $(arquivoFonte1).c
	$(compilador) -o $(arquivoFinal) $(arquivoFonte).o $(arquivoFonte1).o
#Funções para utilização dos arquivos de teste e valgrind
check:
	valgrind --track-origins=yes ./$(executavel) in
check1:
	valgrind --track-origins=yes ./$(executavel) in2
clean:
	rm *.o
	rm $(executavel)
	reset
