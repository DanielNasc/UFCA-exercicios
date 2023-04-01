public class Campeonato {
    Clube[] clubes;
    
    public Campeonato(Clube[] clubes) {
        this.clubes = clubes;
    }

    public void jogarCampeonato() {
        for (int i = 0; i < clubes.length; i++) {
            for (int j = 0; j < clubes.length; j++) {
                if (i == j) continue;
                jogarPartida(clubes[i], clubes[j]);
            }
            System.out.println();
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

        // se houver empate no numero de pontos, o saldo de gols é o criterio de desempate
        for (int i = 0; i < clubes.length; i++) {
            for (int j = i + 1; j < clubes.length; j++) {
                if (clubes[i].pontos == clubes[j].pontos && clubes[i].saldoGols < clubes[j].saldoGols) {
                    Clube aux = clubes[i];
                    clubes[i] = clubes[j];
                    clubes[j] = aux;
                }
            }
        }
    }

    public int sortearGols() {
        return ((int) (Math.random() * 10)) % 6;
    }

    public void jogarPartida(Clube c1, Clube c2) {
        int golsC1 = sortearGols();
        int golsC2 = sortearGols();

        System.out.println(c1.nome + " " + golsC1 + " x " + golsC2 + " " + c2.nome);

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

    public String getClassificacao() {
        sortClubes();
        String classificacao = "";
        for (int i = 0; i < clubes.length; i++) {
            classificacao += (i + 1) + "º " + clubes[i].nome + " com " + clubes[i].pontos + " pontos e saldo de gols de " + clubes[i].saldoGols + ".\n";
        }

        return classificacao;
    }

    public String getCampeao() {
        sortClubes();

        int qtdCampeoes = 1;

        // ver se, mesmo com o sort, houve empate entre os primeiros colocados
        int i = 0;
        while(i < clubes.length - 1 && clubes[i].pontos == clubes[i + 1].pontos && clubes[i].saldoGols == clubes[i + 1].saldoGols) {
            qtdCampeoes++;
            i++;
        }

        if (qtdCampeoes > 1) {
            String campeoes = "Os campeões são: ";
            for (int j = 0; j < qtdCampeoes; j++) {
                campeoes += clubes[j].nome + ", ";
            }

            return campeoes.substring(0, campeoes.length() - 2) + " com " + clubes[0].pontos + " pontos e saldo de gols de " + clubes[0].saldoGols + ".";
        }


        return "O campeão é o " + clubes[0].nome + " com " + clubes[0].pontos + " pontos e saldo de gols de " + clubes[0].saldoGols + ".";
    }
}
