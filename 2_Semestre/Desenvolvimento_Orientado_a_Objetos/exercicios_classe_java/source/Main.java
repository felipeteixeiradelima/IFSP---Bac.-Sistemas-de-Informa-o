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

Tarefa: Criação de Classe no Java
*/

//classe Main
public class Main {

    //método main
    public static void main(String args[]) {
        //criando o objeto/instância carro1
        Carro carro1 = new Carro("VW", "Fusca", "Azul", 1980);

        /*
        atributos de carro1:
            marca = "VW"
            modelo = "Fusca"
            cor = "Azul"
            ano = 1980
        */

        //exibindo modelo, ano e cor do objeto/instância carro1
        carro1.exibirModelo();
        carro1.exibirAnoECor();

        //criando o objeto/instância carro2
        Carro carro2 = new Carro("Ford", "Fiesta", "Vermelho", 2000);

        /*
        atributos de carro2:
            marca = "Ford"
            modelo = "Fiesta"
            cor = "Vermelho"
            ano = 2000
        */

        //exibindo modelo, ano e cor do objeto/instância carro2
        carro2.exibirModelo();
        carro2.exibirAnoECor();

        //criando o objeto/instância carro3
        Carro carro3 = new Carro("Lamborghini", "Huracan", "Amarelo", 2014);

        /*
        atributos de carro3:
            marca = "Lamborghini"
            modelo = "Huracan"
            cor = "Amarelo"
            ano = 2014
        */

        //exibindo modelo, ano e cor do objeto/instância carro3
        carro3.exibirModelo();
        carro3.exibirAnoECor();
    }
}
