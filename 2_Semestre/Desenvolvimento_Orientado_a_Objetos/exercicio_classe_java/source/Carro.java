//classe Carro
public class Carro {
    //atributos da classe Carro
    int ano;
    String marca;
    String modelo;
    String cor;

    //constructor da classe Carro (associa os parâmetros aos atributos da instância)
    Carro(String marca, String modelo, String cor, int ano) {
        this.marca = marca;
        this.modelo = modelo;
        this.cor = cor;
        this.ano = ano;
    }

    //método da classe Carro que exibe o modelo da instância
    public void exibirModelo() {
        System.out.printf("O modelo desse carro é %s %s\n",marca, modelo);
    }

    //método da classe Carro que exibe o ano e a cor da instância
    public void exibirAnoECor() {
        System.out.printf("Esse carro foi fabricado em %d e sua cor é %s\n",ano, cor);
    }
}
