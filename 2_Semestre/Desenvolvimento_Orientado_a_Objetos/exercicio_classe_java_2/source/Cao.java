public class Cao {
    String nome, raca, somLatido;

    Cao (String nome, String raca, String somLatido) {
        this.nome = nome;
        this.raca = raca;
        this.somLatido = somLatido;
    }

    void latir() {
        System.out.printf("%s está latindo: %s\n", nome, somLatido);
    }
}
