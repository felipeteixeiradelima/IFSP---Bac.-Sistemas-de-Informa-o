public class Carro {
    int ano;
    String marca;
    String modelo;
    String cor;

    Carro(String marca, String modelo, String cor, int ano) {
        this.marca = marca;
        this.modelo = modelo;
        this.cor = cor;
        this.ano = ano;
    }

    public void exibirModelo() {
        System.out.printf("O modelo desse carro é %s %s\n",marca, modelo);
    }
    public void exibirAnoECor() {
        System.out.printf("Esse carro foi fabricado em %d e sua cor é %s\n",ano, cor);
    }
}