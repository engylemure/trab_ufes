# UFES - UNIVERSIDADE FEDERAL DO ES
# MAKEFILE PARA O 2° TRABALHO DE ESTRUTURA DE DADOS
# PROFESSOR : THOMAS HAUBER
# ALUNOS : JORDÃO RODRIGUES OLIVEIRA ROSARIO E TADEU ALVES HASTENREITER
compilador = gcc
arquivoFonte = arv
arquivoFonte1 = progarv
executavel = arvore
arquivoFinal = arvore
arquivoFinalexe = arvore
# Compilacao do programa
all:
	$(compilador) -c $(arquivoFonte).c
	$(compilador) -c $(arquivoFonte1).c
	$(compilador) -o $(arquivoFinal) $(arquivoFonte).o $(arquivoFonte1).o -lm
	$(compilador) -o $(arquivoFinalexe).exe $(arquivoFonte).o $(arquivoFonte1).o -lm
run:
	./$(executavel)
# Observação os aquivos de entrada devem estar no mesmo local que o programa
teste1:
	valgrind --track-origins=yes ./$(executavel) grammar/Arvore.lsy Arvore.ps Arvtart.txt
teste2:
	valgrind --track-origins=yes ./$(executavel) grammar/Basic_Y_Fractal.lsy Basic_Y.ps Baytart.txt
teste3:
	valgrind --track-origins=yes ./$(executavel) grammar/cube.lsy cube.ps cubtart.txt
teste4:
	valgrind --track-origins=yes ./$(executavel) grammar/triangle.lsy triangle.ps tritart.txt
teste5:
	valgrind --track-origins=yes ./$(executavel) grammar/heart.lsy heart.ps hearttart.txt
teste6:
	valgrind --track-origins=yes ./$(executavel) grammar/Koch.lsy Koch.ps kochtart.txt
teste7:
	valgrind --track-origins=yes ./$(executavel) grammar/helloworld1.lsy helloworld1.ps hellotart.txt
# Limpeza dos arquivos .o e executaveis gerados pelo comando make all
clean:
	rm *.o
	rm $(executavel)
	reset
