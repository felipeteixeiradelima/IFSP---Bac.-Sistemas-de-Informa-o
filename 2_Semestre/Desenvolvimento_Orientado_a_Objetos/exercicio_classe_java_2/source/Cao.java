//classe Cao
public class Cao {

    //atributos de Cao
    String nome, raca, somLatido;

    //construtor de Cao
    Cao (String nome, String raca, String somLatido) {
        this.nome = nome;
        this.raca = raca;
        this.somLatido = somLatido;
    }

    //metodo latir(): imprime que [nome do cão] está latindo e o som do latido [somLatido]
    void latir() {
        System.out.printf("%s está latindo: %s\n", nome, somLatido);
    }
}
