#ESCREVA SEU CÓDIGO!   <---- ISTO É UM COMENTÁRIO

# Escreva um programa em Python que contenha comandos de entrada, saída, estruturas de repetição
# e estruturas de seleção... 
# Escolha um problema já implementado na disciplina de Introdução a Programação. 

# Faça um algoritmo que receba a idade, sexo (1 - masculino, 2 - feminino) e vacina (1 -
# Tomou, 2 - Não tomou) de n pessoas (n informado pelo usuário).

    # Calcule a média da idade das pessoas do sexo feminino.
    # Calcule a média da idade das pessoas do sexo masculino.
    # Qual o percentual de mulheres que não tomaram vacina?
    # Qual o percentual de homens que tomaram vacina?

# Classe Pessoa
class Pessoa:
    def __init__(self, idade, sexo, vacina):
        self.idade = idade
        self.sexo = sexo
        self.vacina = vacina

def main():
    n = get_int("Digite o número de pessoas: ")
    pessoas: list[Pessoa] = []
    
    print()
    # Criar uma lista de pessoas
    for i in range(n):
        idade = get_int("Digite a idade da pessoa {}: ".format(i+1))
        sexo = get_1_ou_2("Digite o sexo da pessoa {} (1 - masculino, 2 - feminino): ".format(i+1))
        vacina = get_1_ou_2("Digite se a pessoa {} tomou a vacina (1 - sim, 2 - não): ".format(i+1))
        pessoas.append(Pessoa(idade, sexo, vacina))
        print()

    soma_idades_masc = soma_idades_fem = 0
    qtd_masc = qtd_fem = 0
    qtd_homens_vacinados = qtd_mulheres_nao_vacinadas = 0

    # Percorre a lista de pessoas atribuindo valores às variavéis acima
    for pessoa in pessoas:
        if pessoa.sexo == 1:
            soma_idades_masc += pessoa.idade
            qtd_masc += 1
            if pessoa.vacina == 1:
                qtd_homens_vacinados += 1
        else:
            soma_idades_fem += pessoa.idade
            qtd_fem += 1
            if pessoa.vacina == 2:
                qtd_mulheres_nao_vacinadas += 1
    
    # Calculos (os nomes são autoexplicativos)
    media_idades_masc = soma_idades_masc / qtd_masc
    media_idades_fem = soma_idades_fem / qtd_fem
    percentual_homens_vacinados = (qtd_homens_vacinados / qtd_masc) * 100
    percentual_mulheres_nao_vacinadas = (qtd_mulheres_nao_vacinadas / qtd_fem) * 100

    # Imprimir os resultados
    print("A média de idade dos homens é: {}".format(media_idades_masc))
    print("A média de idade das mulheres é: {}".format(media_idades_fem))
    print("O percentual de homens que tomaram a vacina é: {}".format(percentual_homens_vacinados))
    print("O percentual de mulheres que não tomaram vacina é: {}".format(percentual_mulheres_nao_vacinadas))

    return 0

# Pedir para o usuário digitar um inteiro
def get_int(msg):
    while True:
        try:
            numero = int(input(msg))
            break
        except ValueError:
            print("Digite um número inteiro!")
    return numero

# Pedir para o usuário digitar 1 ou 2
def get_1_ou_2(msg):
    while True:
        numero = get_int(msg)
        if not checar_se_1_ou_2(numero):
            print("Digite 1 ou 2!")
        else:
            break
    return numero

# Checa se o input realmente é 1 ou 2
def checar_se_1_ou_2(numero):
    if numero != 1 and numero != 2:
        return False
    return True

# Executa o programa
if __name__ == '__main__':
    main()