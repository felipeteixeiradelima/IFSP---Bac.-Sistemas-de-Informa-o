public class Pessoa {
    String nome;
    int idade;
    Cao pet;

    Pessoa (String nome, int idade, Cao pet) {
        this.nome = nome;
        this.idade = idade;
        this.pet = pet;
    }
    
    void pedirPraCaoLatir() {
        System.out.printf("%s está pedindo para %s latir!\n", nome, pet.nome);
        pet.latir();
    }
}
