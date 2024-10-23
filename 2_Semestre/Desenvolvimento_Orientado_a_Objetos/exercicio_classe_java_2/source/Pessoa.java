//classe Pessoa
public class Pessoa {

    //atriburos de Pessoa
    String nome;
    int idade;
    Cao pet;

    //construtor de Pessoa
    Pessoa (String nome, int idade, Cao pet) {
        this.nome = nome;
        this.idade = idade;
        this.pet = pet;
    }
    
    //método pedirPraCaoLatir(): imprime que [nome da pessoa] está pedindo para [nome do cão] latir e invoca o método latir() do pet
    void pedirPraCaoLatir() {
        System.out.printf("%s está pedindo para %s latir!\n", nome, pet.nome);
        pet.latir();
    }
}
