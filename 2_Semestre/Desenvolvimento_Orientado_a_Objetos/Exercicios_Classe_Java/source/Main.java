public class Main {
    public static void main(String args[]) {
        Carro carro1 = new Carro("VW", "Fusca", "Azul", 1980);

        carro1.exibirModelo();
        carro1.exibirAnoECor();

        Carro carro2 = new Carro("Ford", "Fiesta", "Vermelho", 2000);

        carro2.exibirModelo();
        carro2.exibirAnoECor();

        Carro carro3 = new Carro("Lamborghini", "Huracan", "Amarela", 2014);

        carro3.exibirModelo();
        carro3.exibirAnoECor();
    }
}
