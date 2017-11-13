COMPILADOR := g++ -std=c++11
all:	build clean


build:
	@$(COMPILADOR) util/*.cpp -c -g
	@$(COMPILADOR) ufes_sys/exception/*.cpp -c -g
	@$(COMPILADOR) ufes_sys/sys/*.cpp -c -g
	@$(COMPILADOR) *.cpp -c -g
	@$(COMPILADOR) *.o -o Trabalho -g
run:
	@./Trabalho -c cursos.csv -d disciplinas.csv -a alunos.csv -n notas.csv -p avaliacoes.csv
run-val:
	valgrind --leak-check=full ./Trabalho -c cursos.csv -d disciplinas.csv -a alunos.csv -n notas.csv -p avaliacoes.csv
clean:
	@rm -f *.o
