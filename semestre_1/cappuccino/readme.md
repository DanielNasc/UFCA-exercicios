Cappuccino
====================
Esse é um projeto que um professor passou para uma turma diferente da minha, mas como achei a idéia legal, também vou fazer.

Informações
--------------------
* Cappuccino é um jogo abstrato para até quatro jogadores cujo objetivo é ter a maior
quantidade de pilhas sobre seu domínio ao final da partida. Esse objetivo é alcançado
empilhando peças durante a partida. Neste projeto a versão será apenas para 4 jogadores, não
precisando implementação para 2 ou 3 jogadores.

* A preparação do jogo é realizada colocando peças em um tabuleiro 5x5. Os jogadores
devem ter a mesma quantidade de peças, mas essas peças são posicionadas aleatoriamente.
Os espaços dos cantos e central não possuem nenhuma peça. Necessário o uso de cores para
indicar qual peça é de qual jogador.

* Os jogadores alternam seus turnos durante a partida, durante seu turno o jogador
deverá escolher uma peça e movê-la para um espaço adjacente. Desde modo, o jogador indica
o espaço que ela se encontra (exemplo: a4) e depois indicar uma direção de movimento
(teclado numérico com o 8 indicando cima, 3 diagonal para direita e baixo, etc).

* Movimento: Todas as peças movem-se similar ao Rei do Xadrez. O jogador deverá
escolher uma das oito posições ao seu redor para mover sua peça. Caso o espaço esteja vazio,
não é possível realizar o movimento. Caso o espaço tenha uma peça, ele só poderá se mover
se a peça tiver altura igual ou inferior à sua. Ao mover uma peça para um espaço válido, você
deve empilhar sobre a pilha existente, isto é, se sua peça tinha altura 3 e se move para umespaço com peça de altura 2 no final você terá uma peça de sua cor de altura 5

* O objetivo do jogo é conseguir o maior somatório de alturas. Então, se você terminou
a partida com duas peças, uma de altura 3 e outra de altura 5, você terá 8 pontos. A partida
dura enquanto for possível alguém se movimentar. Isto é, se você passar a vez de todos os
jogadores, pois nenhum é capaz de se mover mais, a partida encerra. Em caso de empates,
usar ordem do turno inversa para desempatar.

⚠️ Warning
--------------------
* Estou desenvolvendo esse projeto em um PC com Linux, que usa formas diferentes de imprimir cores no terminal, por isso não irá funcionar no Windows. <br>
PS: Não sei se funciona no MacOS ou no Windows com WSL

**Em breve atualizo esse md com mais informações**