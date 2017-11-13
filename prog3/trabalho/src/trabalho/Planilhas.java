package trabalho;

import java.io.*;
import java.text.*;
import java.util.*;
import trabalho.exception.*;

/**
 * <i>Documentação da classe Planilhas </i>
 * Classe responsavel por realizar a leitura das informações das planilhas
 * contendo as informações do sistema.
 *
 * @version 1.0
 * @since 05/05/2016
 * @author Jordão e Nicole
 */
public class Planilhas {

    static Locale ptBR = new Locale("pt", "BR");

    public static void LeituraAlunoCSV(Disciplinas d, Alunos a, Cursos c, FileReader arquivo) throws ElementoRepetidoException, DadoInconsistenteException {
        Scanner scan = new Scanner(arquivo);
        scan.useDelimiter(";");
        scan.nextLine();
        int matricula = 0;
        String nome, tipo, coddisc, nomeDoCursoDoAluno;

        while (scan.hasNext()) {
            Aluno alunoauxiliar = null;
            if (scan.hasNextInt()) {
                matricula = scan.nextInt();
            }

            if (null != a.buscaPorMatricula(matricula)) {
                LancaException.E3(matricula);
            }

            nome = scan.next();
            coddisc = scan.next().replace(" ", "").replace(";", "");
            String[] codigoDisciplinas = coddisc.split(",");
            tipo = scan.next().replace(";", "").replace(" ", "");
            nomeDoCursoDoAluno = scan.nextLine().replace(";", "");
            switch (tipo) {
                case "G":
                    Curso curso = c.procuraCurso(Integer.parseInt(nomeDoCursoDoAluno.replace(" ", "")));
                    alunoauxiliar = new Graduando(matricula, nome, curso);
                    break;
                case "P":
                    alunoauxiliar = new PosGraduando(matricula, nome, nomeDoCursoDoAluno);
                    break;
                default:
                    LancaException.E2(matricula, tipo);
                    break;
            }
            Disciplinas disciplinasDoAluno = alunoauxiliar.getDisciplinas();
            //Percorre os codigos das disciplinas matriculadas.
            for (String icodigoDisciplina : codigoDisciplinas) {

                //Procura a disciplina no qual o aluno está matriculada.
                Disciplina matriculada = d.buscaCodigo(icodigoDisciplina);
                //Adiciona a disciplina matriculada nas disciplinas do aluno.
                disciplinasDoAluno.addDisciplina(matriculada);
                //Adiciona o aluno na lista de alunos matriculados na disciplina.
                matriculada.getAlunos().addAluno(alunoauxiliar);
                a.addAluno(alunoauxiliar);
            }
        }
        scan.close();
    }

    public static void LeituraCursoCSV(Cursos cursos, FileReader arquivo) throws ElementoRepetidoException {
        Scanner scan;
        scan = new Scanner(arquivo);
        scan.useDelimiter(";");
        scan.nextLine();
        while (scan.hasNext()) {
            int codigodocurso = 0;
            if (scan.hasNextInt()) {
                codigodocurso = scan.nextInt();
            }

            String nome = scan.nextLine().replace(";", "");
            if (cursos.procuraCurso(codigodocurso) != null) {
                throw new ElementoRepetidoException("Código repetido para curso: " + codigodocurso);
            }
            cursos.addCurso(new Curso(codigodocurso, nome));
        }
        scan.close();

    }

    public static boolean LeituraAvaliacaoCSV(Avaliacoes AVA, Disciplinas D, FileReader arquivo) throws DadoInconsistenteException, ElementoRepetidoException {
        Scanner scan;
        scan = new Scanner(arquivo);
        scan.useDelimiter(";");
        SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy");
        scan.nextLine();
        while (scan.hasNext()) {
            String codigoDisciplina = scan.next().replace(";", "").replace(" ", "");
            String codigoAvaliacao = scan.next().replace(";", "").replace(" ", "");
            String nomeAvaliacao = scan.next().replace(";", "").trim();
            double peso = Double.parseDouble(scan.next().replace(",", ".").replace(" ", ""));
            String tipo = scan.next().replace(";", "").replace(" ", "");
            if (peso <= 0) {
                LancaException.E4(codigoAvaliacao, peso);
            }

            if (!verificaTipoAvaliacao(codigoAvaliacao, tipo)) {
                return false;
            }

            int tamanho;
            Date Data = null;
            String data = scan.nextLine();
            String[] meuamor = data.split(";");
            try {
                Data = formato.parse(meuamor[1]);
            } catch (ParseException ex) {
                System.out.println("Erro de Formatação\n" + ex);
            }
            Avaliacao ava;

            if (tipo.equals("T")) {
                tamanho = Integer.parseInt(meuamor[2]);
                if (tamanho < 1) {
                    LancaException.E5(codigoAvaliacao, tamanho);
                }
                ava = new Trabalho(D.buscaCodigo(codigoDisciplina), codigoAvaliacao, nomeAvaliacao, peso, tipo, tamanho, Data);
            } else {
                if (meuamor.length == 2) {
                    ava = new Avaliacao(D.buscaCodigo(codigoDisciplina), codigoAvaliacao, nomeAvaliacao, peso, tipo, Data);
                } else {

                    tamanho = Integer.parseInt(meuamor[2]);
                    throw new DadoInconsistenteException("Tamanho máximo de grupo especificado para a prova "
                            + codigoAvaliacao + ": " + tamanho + ".");
                }
            }

            AVA.verificaAvaliacaoRepetida(codigoAvaliacao);
            AVA.addAvaliacao(ava);
            //Adiciona avaliacoes na lista de Avaliacoes da disciplina
            ava.getDisciplina().getAvaliacoes().addAvaliacao(ava);
        }
        scan.close();
        return true;
    }

    //Verifica se o tipo de avaliação colocado na planilha é coerente.
    public static boolean verificaTipoAvaliacao(String codigo, String tipo) throws DadoInconsistenteException {
        if (tipo.equals("T") || tipo.equals("P") || tipo.equals("F")) {
            return true;
        }

        throw new DadoInconsistenteException("Tipo de avaliação desconhecido para " + codigo + ": " + tipo);
    }

    public static void LeituraDisciplinaCSV(Disciplinas disciplinas, FileReader arquivo) throws ElementoRepetidoException {
        Scanner scan = new Scanner(arquivo);
        String codigo, nome;
        scan.useDelimiter(";");
        scan.nextLine();
        while (scan.hasNext()) {
            codigo = scan.next().replace(" ", "");
            nome = scan.nextLine().replace(";", "");
            Disciplina existe = null;
            Disciplina disciplina = new Disciplina(codigo, nome);
            existe = disciplinas.buscaCodigo(disciplina.getCodigo());
            if (existe == null) {
                disciplinas.addDisciplina(disciplina);
            } else {
                throw new ElementoRepetidoException("Código repetido para disciplina: " + existe.getCodigo());
            }
        }
        scan.close();
    }

    /**
     * É a única planilha dependente das demais.
     */
    public static void LeituraNotaCSV(Avaliacoes AVA, Alunos alunos, FileReader arquivo) throws ErroDeConsistenciaException, DadoInconsistenteException {
        Scanner scan = new Scanner(arquivo);
        String codigo;
        double nota;
        scan.useDelimiter(";");
        scan.nextLine();
        while (scan.hasNext()) {
            codigo = scan.next();
            Avaliacao ava = AVA.buscaAvaliacao(codigo);

            int[] vetMatriculas;
            String matriculasString;
            matriculasString = scan.next().replace(";", "");
            if (ava == null) {
                throw new ErroDeConsistenciaException("Código de avaliação não definido usado na planilha de notas , associado ao(s) aluno(s)"
                        + matriculasString);
            }
            String tipo = ava.getTipo();
            if (tipo.equals("P") || tipo.equals("F")) {
                vetMatriculas = new int[1];

                String notaString = scan.nextLine().replace(";", "").replace(",", ".").replace(" ", "");

                nota = Double.parseDouble(notaString);
                matriculasString = matriculasString.replace(" ", "");
                vetMatriculas[0] = Integer.parseInt(matriculasString);
                Aluno a = alunos.buscaPorMatricula(vetMatriculas[0]);
                if (a == null) {
                    throw new DadoInconsistenteException("Matrícula de aluno não definida usada na planilha de notas, associada à avaliação "
                            + tipo + ": " + vetMatriculas[0]);
                }
                Disciplinas auxdisciplinas = a.getDisciplinas();

                if (auxdisciplinas.buscaCodigo(ava.getDisciplina().getCodigo()) == null) {
                    throw new DadoInconsistenteException("O aluno " + vetMatriculas[0] + " possui nota na avaliação " + codigo
                            + " da disciplina " + ava.getDisciplina().getCodigo() + ", porém não encontra-se matriculado nesta disciplina.");
                }
            } else {

                nota = Double.parseDouble(scan.nextLine().replace(";", "").replace(",", "."));
                if (nota > 10.0 || nota < 0.0) {
                    LancaException.E7(codigo, matriculasString, nota);
                }
                matriculasString = matriculasString.replace(" ", "");
                String[] vetor = matriculasString.split(",");
                int i = 0;
                int matricula;
                vetMatriculas = new int[vetor.length];
                for (String aux : vetor) {
                    vetMatriculas[i] = Integer.parseInt(aux);
                    i++;
                }

                for (i = 0; i < vetMatriculas.length; i++) {
                    Aluno a = alunos.buscaPorMatricula(vetMatriculas[i]);
                    if (a == null) {
                        throw new DadoInconsistenteException("Matrícula de aluno não definida usada na planilha de notas, associada à avaliação "
                                + tipo + ": " + vetMatriculas[i]);
                    }
                    //Verifica se o aluno está matriculado na disciplina desse avaliacao
                    Disciplinas auxdisciplinas = a.getDisciplinas();
                    if (auxdisciplinas.buscaCodigo(ava.getDisciplina().getCodigo()) == null) {
                        throw new DadoInconsistenteException("O aluno " + vetMatriculas[i] + " possui nota na avaliação " + codigo
                                + " da disciplina " + ava.getDisciplina().getCodigo() + ",porém não encontra-se matriculado nesta disciplina.");
                    }

                    //Busca dentro destas notas se o aluno já foi matriculado em algum grupo.
                    for (Nota inota : ava.getNotas().notas) {
                        for (Aluno ialuno : inota.getAlunos()) {
                            if (ialuno.equals(alunos.buscaPorMatricula(vetMatriculas[i]))) {
                                throw new DadoInconsistenteException("O aluno " + vetMatriculas[i] + " foi registrado em mais de um grupo para a avaliação "
                                        + codigo);
                            }
                        }
                    }

                }

            }

            Aluno[] auxalunos = new Aluno[vetMatriculas.length];
            int i = 0;
            for (int imatricula : vetMatriculas) {
                auxalunos[i++] = alunos.buscaPorMatricula(imatricula);
            }
            Nota notaAluno = new Nota(nota, ava, auxalunos);
            for (Aluno ialuno : auxalunos) {
                ialuno.getNotas().notas.add(notaAluno);
            }
            ava.getNotas().notas.add(notaAluno);
        }
    }
}
