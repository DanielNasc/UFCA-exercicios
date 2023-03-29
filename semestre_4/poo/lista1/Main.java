/*
 * Todos os clubes se enfrentam entre si em jogos de ida e volta;
 * Um vitória vale 3 pontos, um empate vale 1 ponto e uma derrota não pontua;
 * Ao final do campeonato, o clube com maior pontuação é o campeão;
 * Em caso de empate no número de pontos, o saldo de gols deverá ser o critério de desempate;
 * O saldo de gols é a diferença entre gols feitos e gols sofridos em todo o campeonato.
 * 
*/

public class Main {
    public static void main(String[] args) {
        Clube[] clubes = new Clube[4];
        clubes[0] = new Clube("São Paulo");
        clubes[1] = new Clube("Palmeiras");
        clubes[2] = new Clube("Corinthians");
        clubes[3] = new Clube("Flamengo");

        Campeonato campeonato = new Campeonato(clubes);
        campeonato.jogarCampeonato();
        campeonato.getClassificacao();
        campeonato.getCampeao();
    }
}
