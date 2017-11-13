#Nome do arquivo de entrada
program_name = programa.out

#Nome do arquivo de saidas
out_file = Saida.bin

#Potencia inicial, nos testes ira variar do valor a +2 dele
pot_initial = 20

#Comando de compilação
build:
	gcc -c *.c
	gcc *.o -lm -o ${program_name}

#Comando de Limpeza
clear:
	rm *.o
	rm ${program_name}
	rm *.bin

#Comando para execução do teste b, recebe de entrada nos parametros argv o nome do arquivo de saida
run:
	./${program_name} ${pot_initial} ${out_file}

#Compilação
all:	build