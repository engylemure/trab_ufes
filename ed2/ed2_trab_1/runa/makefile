#Nome do programa
program_name = programa.out

#Nome do arquivo de saida
out_file = Saida.bin

#Nome do arquivo de entrada
in_file = entrada.txt

#Numero de registros em memoria principal
m = 3
#Numero de arquivos para intercalação(Ordem Intercalação)
f = 2

#Comando para compilar
build:
	gcc -c *.c
	gcc *.o -lm -o ${program_name}

#Comando para limpar
clear:
	rm *.o
	rm ${program_name}
	rm *.bin

#Comando para compilação
all:	build

#Comando para execução do teste a, recebe de entrada nos parametros argv o nome do arquivo de entrada e ssaida
run:
	./${program_name} ${in_file} ${out_file} ${m} ${f}