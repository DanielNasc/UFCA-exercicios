public class Campeonato {
    Clube[] clubes;
    
    public Campeonato(Clube[] clubes) {
        this.clubes = clubes;
    }

    public void jogarCampeonato() {
        for (int i = 0; i < clubes.length; i++) {
            for (int j = i + 1; j < clubes.length; j++) {
                jogarPartida(clubes[i], clubes[j]);
            }
        }
    }

    private void sortClubes() {
        // sao poucos clubes, entao o bubble sort é o suficiente
        for (int i = 0; i < clubes.length; i++) {
            for (int j = i + 1; j < clubes.length; j++) {
                if (clubes[i].pontos < clubes[j].pontos) {
                    Clube aux = clubes[i];
                    clubes[i] = clubes[j];
                    clubes[j] = aux;
                }
            }
        }
    }

    public int sortearGols() {
        return ((int) (Math.random() * 10)) % 5;
    }

    public void jogarPartida(Clube c1, Clube c2) {
        int golsC1 = sortearGols();
        int golsC2 = sortearGols();

        if (golsC1 > golsC2) {
            c1.ganhar(golsC1 - golsC2);
            c2.perder(golsC2 - golsC1);
        } else if (golsC1 < golsC2) {
            c1.perder(golsC1 - golsC2);
            c2.ganhar(golsC2 - golsC1);
        } else {
            c1.empatar();
            c2.empatar();
        }
    }

    public void getClassificacao() {
        sortClubes();
        for (int i = 0; i < clubes.length; i++) {
            System.out.println((i + 1) + "º " + clubes[i].nome + " - " + clubes[i].pontos + " pontos");
        }
    }

    public void getCampeao() {
        sortClubes();
        System.out.println("O campeão é o " + clubes[0].nome + " com " + clubes[0].pontos + " pontos");
    }
}
