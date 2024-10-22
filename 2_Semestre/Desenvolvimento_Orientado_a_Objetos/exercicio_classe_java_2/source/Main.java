/*
     ___  ______  ______  ______
    /  / /  ___/ /  ___/ / __  /
   /  / /  /__  /  /__  / /_/ /
  /  / /  ___/ /__   / /  ___/
 /  / /  /    ___/  / /  /
/__/ /__/    /_____/ /__/


INSTITUTO FEDERAL DE EDUCACAO, CIENCIA E TECNOLOGIA DE SAO PAULO (IFSP)

SPODEOO - Desenvolvimento Orientado a Objetos | Profª Natalia Patricia Montanher

Aluno: Felipe Teixeira de Lima
RA: SP3515048

Tarefa: Criação de Classe no Java 2
*/

//classe Main
class Main {

    //método main
    public static void main (String[] args) {

        //criação das instâncias da classe Cao cao1 e cao2, com seus atributos (nome, raça e latido)
        Cao cao1 = new Cao("Demolidor", "Pincther", "au au au grrrgggrrrrrgrggrgggrgggrrrrrrrrrrrrrrr");
        Cao cao2 = new Cao("Fafá", "Dogue Alemão", "rooof rooof rooof");

        //criação das instâncias da classe Pessoa pessoa1 e pessoa2, com seus atributos (nome, idade e pet)
        Pessoa pessoa1 = new Pessoa("Joao", 50, cao2);
        Pessoa pessoa2 = new Pessoa("Sabrino", 35, cao1);

        //chamando o método pedirPraCaoLatir() de cada instância de Pessoa, que imprime na tela que a pessoa pediu para o cão latir e o latido do cão
        pessoa1.pedirPraCaoLatir();
        pessoa2.pedirPraCaoLatir();

        //chamando o método latir() do pet de cada instância de Pessoa, que imprime na tela o latido do cão
        pessoa1.pet.latir();
        pessoa2.pet.latir();
    }
}
