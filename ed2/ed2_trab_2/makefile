all:	build_arvore	build_hash

run_indice_arvore:
	./exec_arvore.out Texto.txt Palavras_Chave.txt Alfabeto.txt 1

run_indice_hash:
	./exec_hash.out Texto.txt Palavras_Chave.txt Alfabeto.txt 1

run_busca_arvore:
	./exec_arvore.out Texto.txt Palavras_Chave.txt Alfabeto.txt 2

run_busca_hash:
	./exec_hash.out Texto.txt Palavras_Chave.txt Alfabeto.txt 2

build_arvore:
	gcc -c arvore/*.c -lm
	gcc -o exec_arvore.out *.o
	rm *.o

build_hash:
	gcc -c hash/*.c -lm
	gcc -o exec_hash.out *.o -lm
	rm *.o

clear:
	rm *.out
