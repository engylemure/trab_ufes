-- UNIVERSIDADE FEDERAL DO ESPIRITO SANTO (UFES)
-- TRABALHO DE PROGRAMAÇÃO 1
-- PROF. CLAUDIA BOERES
-- JORDÃO R.O.ROSARIO E FELIPE GANTE

-- JOGO DE CACA-PALAVRAS COM CUSTOS

import Data.List
-- Função de matriz linha e coluna
matrizlinha xs x = if null xs --Função para a criação de uma lista de linhas do caça palavras tem como entrada xs sendo uma string e x sendo o tamanho da linha.
                   then []
                   else [take x xs] ++ matrizlinha (drop x xs) x
matrizcoluna xs x = transpose (matrizlinha xs x) {-Função para a criação de uma lista de colunas do caça palavras tem como entrada xs sendo uma string
 e x sendo o tamanho da linha.-} 
revertelista xs = [reverse x| x<-xs] --Função para reverter cada uma das listas secundarias contidas em uma lista primaria.

--Funções de entrada/teste
palavras = ["AULA", "ALEGRIA", "CAPELA", "FLORESTA", "LAPIS"]
palavras1 = ["LAPIS", "CAPELA", "FLORESTA", "ALEGRIA"]
palavras2= ["SABONETE", "SALSICHA", "MANTEIGA", "LIMAO", "PICLES", "JACA"]
palavrastrabprog = ["AMOR", "TRABALHO", "MATEMATICA", "CALCULO", "INTEGRAL", "AREA"]


cpalavras = ['F','L','O','R','E','S','T','A','R','S', 
             'K','J','G','D','F','T','J','J','U','V',
             'C','A','P','E','L','A','P','I','S','C',
             'D','T','C','A','D','W','Y','E','R','T',
             'F','D','C','C','S','A','L','U','S','E',
             'Q','L','K','C','A','U','E','A','I','O',
             'A','A','S','A','R','P','R','D','K','A',
             'N','E','N','E','F','T','E','B','A','U',
             'J','K','D','D','S','H','W','L','F','L',
             'I','O','T','U','G','J','J','V','A','A']
 
cpalavras1 = ['S', 'A', 'B', 'O', 'N', 'E', 'T', 'E', 'J', 'P',
			  'A', 'M', 'H', 'G', 'J', 'L', 'P', 'J', 'A', 'I',
			  'L', 'I', 'M', 'A', 'O', 'L', 'V', 'W', 'C', 'C',
			  'S', 'A', 'B', 'O', 'N', 'E', 'T', 'E', 'A', 'L',
			  'I', 'Q', 'F', 'C', 'T', 'M', 'U', 'H', 'T', 'E',
			  'C', 'W', 'Z', 'S', 'E', 'Y', 'K', 'J', 'I', 'S',
			  'H', 'G', 'D', 'N', 'X', 'C', 'Q', 'J', 'A', 'L',
			  'A', 'R', 'U', 'I', 'N', 'U', 'S', 'A', 'C', 'O',
			  'K', 'F', 'P', 'O', 'W', 'Q', 'T', 'K', 'A', 'D',
		      'M', 'A', 'N', 'T', 'E', 'I', 'G', 'A', 'J', 'D']
			  
cpaltrabprog =['M','L','A','R','G','E','T','N','I','F',
               'A','C','I','T','A','M','E','T','A','M',
			   'M','O','T','J','A','O','O','U','B','M',
			   'A','L','V','A','R','E','A','A','F','I',
			   'T','U','P','O','Y','H','O','N','D','Y',
			   'O','C','O','H','L','A','B','A','R','T',
			   'U','L','Z','O','Q','A','A','C','O','A',
			   'Q','A','L','S','J','U','I','Z','U','U',
			   'O','C','Q','S','O','Y','A','M','O','R']
		  
custoletra :: [(Char,Int)]
			  
custoletra = [('A',1),('B',10),('C',18),('D',38),('E',70),('F',10),('G',43),('H',15),('I',54),('J',10),('K',44),('L',81),('M',19),('N',39),('O',54),('P',91),('Q',72),('R',30),('S',84),('T',75),('U',22),('V',47),('X',66),('Y',59),('Z',32)]

--Funções de Custo
custocpal xs ys = if null ys {-Função para o calculo do custo de varias palavras, tem como entrada xs sendo a lista de custos e ys a lista de palavras
da como saida uma lista de tuplas, onde o primeiro elemento é a palavra e o segundo o seu custo-}
                  then []
                  else [(head ys, custo xs (head ys))] ++ custocpal xs (tail ys)
				  
custo x xs = if null x {- Função para calculo do custo de uma unica palavra, tem como entrada xs sendo uma palavra(string)
 e ys sendo a lista de custos(lista de tuplas, cujo primeiro elemento é um char e segundo elemento é um numero).-} 
             then 0
             else (length (pospert l xs))*c + custo (tail x) xs
             where 
             l = fst (head x)
             c = snd (head x)
			 
--Funções de Posição e Pertinencia

pospert x xs = [  y | y<-[0,1..length xs-1], xs!!y == x] {-Função para o calculo das posições em que uma letra se encontra em uma palavra-}


--Funções de Prefixo, Sufixo e Sublista

prefixo xs ys = xs == take n ys {-Função para verificar se uma lista é o inicio de outra lista-}
                where
                n = length xs
				
sublista xs ys = if null ys  {-Função para verificar se uma lista está contida em outra lista-}
                 then False
                 else  prefixo xs ys || sublista xs (tail ys)

--Função de caçar a palavra
subl xs ys = if null ys {-Função para verificar se uma lista é sublista de alguma lista de uma lista de listas-}
             then False
			 else sublista xs (head ys) || subl xs (tail ys)
			 
pertcpal pal cpal n = subl pal (matrizlinha cpal n) || subl pal (matrizcoluna cpal n) || subl pal (revertelista (matrizlinha cpal n)) || subl pal (revertelista (matrizcoluna cpal n))
{-Função para verificar se uma palavra pertence ao caça palavras-}
palpertcpal pal cpal n = [ x | x<-pal, pertcpal x cpal n]	
{-Função que verifica se uma lista de palavras está contida em um caça palavras, as palavras que estiverem são retornadas em uma lista-}				          


--Função de ocorrencimc exercicio 01

ocorrenciamc pal cpal x lc = if null (palpertcpal pal cpal x) {-Função que verifica a palavra de uma lista de palavras dada como entrada 
que possui menor custo, de acordo com a lista de custos dada como entrada -}
                             then error " Nenhuma palavra encontrada na matriz!"
                             else menorcusto
                             where                             
                             menorcusto = [ z |  z<-custocp,  (snd z) == minimum (custos (palpertcpal pal cpal x) lc )]
                             custocp = custocpal lc (palpertcpal pal cpal x)
							 				 
custos xs ys = [custo ys x | x<-xs] {-Função que tem como entrada uma lista de palavras e uma lista de custos,
 gera como saida uma lista dos custos das palavras de forma respectiva-}


--Função do numero de ocorrencias exercicio 02

poscpal xs cpal y = (xs, [ x + 1 | x<-[0..(length (matrizlinha cpal y))-1], sublista xs ((matrizlinha cpal y)!!x) ] ++ [ z + 1| z<-[0..(length (matrizcoluna cpal y))-1], sublista xs ((matrizcoluna cpal y)!!z)])
{-Função que informa a posição de uma palavra no caça palavras-} 
poscpalr xs cpal y = (xs, [ x + 1 | x<-[0..(length (matrizlinha cpal y))-1], sublista xs (reverse ((matrizlinha cpal y)!!x)) ] ++ [ z + 1| z<-[0..(length (matrizcoluna cpal y))-1], sublista xs (reverse((matrizcoluna cpal y)!!z))])
{-Função que informa a posição de uma palavra no caça palavras-}

--ocorrencias

ocorcpal xs cpal y  = (xs, length (snd (poscpal xs cpal y)) + length (snd (poscpalr xs cpal y)))
{-Função que informe o numero de veze que uma palavra ocorre em um caça palavras, ela tem como entrada xs sendo uma palavra(string)
 cpal como sendo o caçapalavras(string) y sendo a dimensão e gera como saida uma lista de tuplas com a palavra e o numero de vezes que ela ocorreu -}


occapal xs cpal y = [ocorcpal x cpal y | x<- xs]
{-Função que gera uma lista de tuplas, onde o primeiro elemento de cada tupla é a palavra(string) utilizada na verificação dentro do caça palavras 
e o segundo elemento é o numero de ocorrencias do mesmo.-}

nocorrencias pal cpal x = occapal (ordena (palpertcpal pal cpal x)) cpal x 
{-Função que dada uma palavra retorna somente as palavras que ocorrem no caça palavras dentro de uma lista de tuplas, onde o primeiro elemento é a palavra
e o segundo é o numero de ocorrencias da mesma. essa lista e dada de forma ordenada.-}

--ordena
insertcresc x xs = if null xs {-Função de inserção de um numero ou char em uma lista crescente de numeros ou char na posição ordenada-}
                   then x:xs
                   else if x > head xs 
                   then head xs : insertcresc x (tail xs)
                   else x : xs
				   
ordena xs = if null xs {-Função que ordena de modo crescente uma lista desordenada-}
                 then []
                 else insertcresc (head xs) (ordena (tail xs))
				 
--Função palavrasmaiscaras exercicio 03

palavrasmaiscaras pal cpal x lc =  orddecresc (valcusto pal cpal x lc)
inscresc x xs = if null xs {-Função que insere uma tupla em uma lista de tupla já ordenada em função do segundo elemento da tupla-}
                then x : xs
                else if snd x > snd (head xs)
                then head xs :  inscresc x (tail xs)
                else x : xs
				
ordcresc xs = if null xs {-Função que ordena de forma crescente uma lista de tuplas em função do segundo elemento da tupla-}
              then []
              else inscresc (head xs) (ordcresc (tail xs))
			  
orddecresc xs = reverse (ordcresc xs) {-Função que ordena de forma decrescente uma lista de tuplas em função do segundo elemento da tupla-}

valcusto pal cpal x lc = [(y, custo lc y) | y<-(palpertcpal pal cpal x)] {-Função que retorna a lista de palavras a serem testadas que existem no caçapalavras
e seu custo dentro de uma tupla, criando assim uma lista de tuplas, onde o primeiro elemento da tupla é a palavra e o segundo elemento é o custo da mesma-} 

--Função dadospalavra exercicio 4
dadospalavra pal cpal x = [dados y cpal x | y<- ordena (palpertcpal pal cpal x)]

dados xs cpal x = (xs, poslinha xs cpal x ++ poslinhar xs cpal x ++ poscoluna xs cpal x ++ poscolunar xs cpal x)

poslinha pal cpal x = if null (snd (poscpal pal cpal x))
                      then []
					  else if subl pal m 
                      then [((posli pal m),"horizontal-esquerda-direita")]
					  else []
                     where 
					 m = matrizlinha cpal x
					 
poslinhar pal cpal x = if null (snd (poscpalr pal cpal x))
                       then []
					   else if subl pal m
                       then [((posli pal m),"horizontal-direita-esquerda")] 
                       else []
					   where 
					 m = revertelista (matrizlinha cpal x)
					 
poscoluna pal cpal x = if null (snd (poscpal pal cpal x))
                       then []
					   else if subl pal m
                       then [((posli pal m),"vertical-topo-base")] 
                       else []
					 where 
					 m = matrizcoluna cpal x
					 
poscolunar pal cpal x = if null (snd (poscpalr pal cpal x))
                       then []
					   else if subl pal m 
                       then [((posli pal m),"vertical-base-topo")] 
					   else []
                     where 
					 m = revertelista (matrizcoluna cpal x)
					 
cl pal xs = if prefixo pal xs 
            then 0				 
            else cl pal (tail xs) + 1
			
posli pal xs = [cl pal x | x<-xs, sublista pal x]
 	
--Função direção exercicio 05
direcao pal cpal x = if octotal pal (occpl pal cpal x) == octotal pal (occpc pal cpal x) {-Função que informa a direção que mais palavras foram encontradas: vertical
ou horizontal. Informa também a quantidade de palavras encontradas na direção.-}

                     then ("Ambas as direcoes!", octotal pal (occpl pal cpal x))
					 else if octotal pal (occpl pal cpal x) > octotal pal (occpc pal cpal x)
					 then ("Horizontal",octotal pal (occpl pal cpal x))
                     else ("Vertical", octotal pal (occpc pal cpal x))
					 
pospl xs cpal y =[ x + 1 | x<-[0..(length (matrizlinha cpal y))-1], sublista xs ((matrizlinha cpal y)!!x)]++[ x + 1 | x<-[0..(length (matrizlinha cpal y))-1], sublista xs (reverse ((matrizlinha cpal y)!!x))]

pospc xs cpal y =[ x + 1 | x<-[0..(length (matrizcoluna cpal y))-1], sublista xs ((matrizcoluna cpal y)!!x)]++[ x + 1 | x<-[0..(length (matrizcoluna cpal y))-1], sublista xs (reverse ((matrizcoluna cpal y)!!x))]

ocposl xs cpal y  = (xs, length (pospl xs cpal y))

ocposc xs cpal y  = (xs, length (pospc xs cpal y))

occpl xs cpal y = [ocposl x cpal y | x<- xs]

occpc xs cpal y = [ocposc x cpal y | x<- xs]

octotal xs ys = if null ys
                 then 0
				 else snd (head ys) + octotal xs (tail ys)

				 
--Função saida exercicio 6			 
linha3=(ocorrenciamc (criapal palinha) (tiraesp capalinha) (crianum linha1) custoletra)
linha4=[(nocorrencias (criapal palinha) (tiraesp capalinha) (crianum linha1))]
linha5=[(palavrasmaiscaras (criapal palinha) (tiraesp capalinha) (crianum linha1) custoletra)]
linha6=[(dadospalavra (criapal palinha) (tiraesp capalinha) (crianum linha1))]
linha7=[(direcao (criapal palinha) (tiraesp capalinha) (crianum linha1))]
linha = "AULA,ALEGRIA,CAPELA,FLORESTA,LAPIS"
palinha = "AMOR,TRABALHO,MATEMATICA,CALCULO,INTEGRAL,AREA"
linha1 = "\n10\n"
linha2 = "FLORESTARS\nKJGDFTJJUV\nCAPELAPISC\nDTCADWYERT\nFDCCSALUSE\nQLKCAUEAIO\nAASARPRDKA\nNENEFTEBAU\nJKDDSHWLFL\nIOTUGJJVAA\n"
capalinha= ['M','L','A','R','G','E','T','N','I','F','\n',
            'A','C','I','T','A','M','E','T','A','M','\n',
			'M','O','T','J','A','O','O','U','B','M','\n',
			'A','L','V','A','R','E','A','A','F','I','\n',
			 'T','U','P','O','Y','H','O','N','D','Y','\n',
			   'O','C','O','H','L','A','B','A','R','T','\n',
			   'U','L','Z','O','Q','A','A','C','O','A','\n',
			   'Q','A','L','S','J','U','I','Z','U','U','\n',
			   'O','C','Q','S','O','Y','A','M','O','R','\n']
tiraesp xs = if null xs 
             then []
			 else if head xs == '\n'
			 then  tiraesp (tail xs)
			 else  head xs : tiraesp (tail xs)
tirav xs = [if x == ',' then ' ' else x | x<-xs]
criapal xs = words (tirav xs)
crianum xs = read (tiraesp xs) :: Int
credits = do putStr " I am not responsible of this code.\n They made me write it, against my will \n I am not sure why this works but it fixes the problem. \n no comments for you it was hard to write so it should be hard to read \n I have to find a better job \n───────────▄▄▄█▄▄█▄▄█▄▄▄\n────────▄▀▀═════════════▀▀▄\n───────█═══════════════════█\n──────█═════════════════════█\n─────█═══▄▄▄▄▄▄▄═══▄▄▄▄▄▄▄═══█\n────█═══█████████═█████████═══█\n────█══██▀────▀█████▀────▀██══█\n───██████──█▀█──███──█▀█──██████\n───██████──▀▀▀──███──▀▀▀──██████\n────█══▀█▄────▄██─██▄────▄█▀══█...\nBye and thank you.\n"
saida = do
putStr "\nCaso queira mudar o caca palavras, dimensao e as palavras e necessario que modifique as constantes linha1,capalinha e palinha dentro do script\n"
writeFile "saida.txt"( "\n"++(palinha) ++ "\n" ++(linha1) ++ "\n" ++ (capalinha) ++ "\n" ++ "\n" ++ (show linha3) ++ "\n"++ (show linha4) ++"\n"++ (show linha5) ++"\n"++ (show linha6) ++"\n"++ (show linha7) ++ "\n")









			
