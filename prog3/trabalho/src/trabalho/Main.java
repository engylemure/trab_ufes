package trabalho;

import java.io.*;
import trabalho.exception.*;

/**
 * <i>Documentação da classe Main </i>
 *
 * @version 1.0
 * @since 05/05/2016
 * @author Jordão e Nicole
 */
public class Main {

    /**
     * @param args the command line arguments
     * @throws java.io.FileNotFoundException
     */
    public static void main(String[] args) throws IOException {


        
        //1ª Etapa:Verificação do tipo de leitura
        int tipo;
        String[] nomearquivos = new String[5];
        Cursos C;
        Disciplinas D;
        Alunos AL;
        Avaliacoes AVA;
        try {
            tipo = processamentoDeEntrada(args, nomearquivos);
            if (tipo == 1) {
                //Modo leitura
                //1ª Etapa: Criação das listas
                C = new Cursos();
                D = new Disciplinas();
                AL = new Alunos();
                AVA = new Avaliacoes();

                //2ª Etapa: Ler os Arquivos. Verificar erros na leitura e linkar as estruturas
                Main.leituras(C, D, AL, AVA, nomearquivos);

                //3ª Serialização das estruturas
                ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("semestre.dat"));
                out.writeObject(C);
                out.writeObject(D);
                out.writeObject(AVA);
                out.writeObject(AL);
                out.close();

            } else if (tipo == 0) {
                /* Modo normal */
                //1ª Etapa: Criação das listas
                C = new Cursos();
                D = new Disciplinas();
                AL = new Alunos();
                AVA = new Avaliacoes();

                //2ª Etapa: Ler os Arquivos. Verificar erros na leitura.
                Main.leituras(C, D, AL, AVA, nomearquivos);
                //3ª Etapa:Geração de relatórios
                Relatorios.geraRelatorioDisciplinas(D);
                Relatorios.geraRelatorioEstatisticaPorDisciplina(D);
                Relatorios.geraRelatorioAavaliacoes(D);
            } else if (tipo == -1) {
                // Modo escrita
                // 1ª Etapa: Leitura dos objetos pela serialização
                ObjectInputStream in = new ObjectInputStream(new FileInputStream("semestre.dat"));
                C = (Cursos) in.readObject();
                D = (Disciplinas) in.readObject();
                AVA = (Avaliacoes) in.readObject();
                AL = (Alunos) in.readObject();

                //2ª Etapa: geração de relatórios
                Relatorios.geraRelatorioDisciplinas(D);
                Relatorios.geraRelatorioEstatisticaPorDisciplina(D);
                Relatorios.geraRelatorioAavaliacoes(D);
            }
        } catch (NumberFormatException | ClassNotFoundException | DadoInconsistenteException | ElementoRepetidoException | ErroDeConsistenciaException | DisciplinaNaoEncontradaException | IOException | DadoAusenteException e) {
            if (e instanceof IOException) {
                System.out.println("Erro de I/O");
            } else if (e instanceof NumberFormatException) {
                System.out.println("Erro de Formatação");
            } else {
                System.out.println(e.getMessage());
            }

        }

    }

    public static int processamentoDeEntrada(String[] args, String[] s){
        int tipoDePrograma = -2;
        if(args.length <1) return tipoDePrograma;
        else tipoDePrograma = 0;
        for (int i = 0; i < args.length; i++) {
            switch (args[i]) {
                case "-c":
                    s[0] = args[i + 1];
                    break;
                case "-d":
                    s[1] = args[i + 1];
                    break;
                case "-p":
                    s[2] = args[i + 1];
                    break;
                case "-n":
                    s[3] = args[i + 1];
                    break;
                case "-a":
                    s[4] = args[i + 1];
                    break;
                case "--read-only":
                    tipoDePrograma = 1;
                    break;
                case "--write-only":
                    tipoDePrograma = -1;
                    break;
            }
        }
        return tipoDePrograma;
    }

    public static void leituras(Cursos C, Disciplinas D, Alunos AL, Avaliacoes AVA, String[] nomearquivos) throws FileNotFoundException, ElementoRepetidoException, DadoInconsistenteException, ErroDeConsistenciaException, DisciplinaNaoEncontradaException {

        try {
            FileReader arquivocursos = new FileReader(nomearquivos[0]);
            FileReader arquivodisci = new FileReader(nomearquivos[1]);
            FileReader arquivoaval = new FileReader(nomearquivos[2]);
            FileReader arquivonota = new FileReader(nomearquivos[3]);
            FileReader arquivoalun = new FileReader(nomearquivos[4]);
            Planilhas.LeituraCursoCSV(C, arquivocursos);
            Planilhas.LeituraDisciplinaCSV(D, arquivodisci);
            Planilhas.LeituraAvaliacaoCSV(AVA, D, arquivoaval);
            Planilhas.LeituraAlunoCSV(D, AL, C, arquivoalun);
            Planilhas.LeituraNotaCSV(AVA, AL, arquivonota);
        } catch (FileNotFoundException e) {
            System.out.println("Erro de I/O");
        }

    }

}
