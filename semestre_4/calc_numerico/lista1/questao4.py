"""
(Adaptado de Maratona de Programação da SBC 2013). Todos devem conhe-
cer o jogo Zerinho ou Um (em algumas regiões também conhecido como Dois ou Um),
utilizado para determinar um ganhador entre três ou mais jogadores. Para quem não co-
nhece, o jogo funciona da seguinte maneira. Cada jogador escolhe um valor entre zero
ou um; a um comando (geralmente um dos competidores anuncia em voz alta “Zerinho
ou... Um!”), todos os participantes mostram o valor escolhido, utilizando uma das mãos:
se o valor escolhido foi um, o competidor mostra o dedo indicador estendido; se o valor
escolhido foi zero, mostra a mão com todos os dedos fechados. O ganhador é aquele que
tiver escolhido um valor diferente de todos os outros; se não há um jogador com valor
diferente de todos os outros (por exemplo todos os jogadores escolhem zero, ou um grupo
de jogadores escolhe zero e outro grupo escolhe um), não há ganhador. Você deve escre-
ver uma função em Python que determina se há um ganhador, e nesse caso determina qual
o número correspondente ao ganhador.
A entrada de sua função deve consistir de um arranjo x da numpy contendo as escolhas
de n > 1 jogadores. Sua função deve retornar o par (True, i) para indicar quando o i-
ésimo jogador venceu a partida, ou None, caso contrário.
"""

import numpy as np

def zeroouum(x):
    index = np.where(x == 1)
    
    if len(index[0]) == 1 or (len(x) - len(index[0]) == 1):
        return (True, 
                index[0][0] if len(index[0]) == 1 else np.where(x == 0)[0][0]
                )

if __name__ == '__main__':
    print(zeroouum(np.array([0, 0, 0, 0, 0])))
    print(zeroouum(np.array([1, 1, 1, 1, 1])))
    print(zeroouum(np.array([1, 0, 1, 0, 1])))
    print(zeroouum(np.array([0, 0, 1, 0, 0, 0])))
    print(zeroouum(np.array([1, 1, 1, 1, 0, 1])))