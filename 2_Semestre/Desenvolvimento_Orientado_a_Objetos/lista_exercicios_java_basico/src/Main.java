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

Tarefa: lista de exercícios em java básico
*/

import java.util.Scanner;

public class Main {
    public static void ex1_idade() {
        Scanner scanner = new Scanner(System.in);
        int anos, meses, dias;
        System.out.println("Digite sua idade em anos, meses e dias:");
        System.out.print("Anos: ");
        anos = scanner.nextInt();
        System.out.print("Meses: ");
        meses = scanner.nextInt();
        System.out.print("Dias: ");
        dias = scanner.nextInt();
        anos*=365;
        meses*=30;
        dias+=anos+meses;
        System.out.println("\nVocê tem "+dias+" dias de idade!");
    }
    
    public static void ex2_media() {
        double media = (8+9+7)/3;
        System.out.printf("A média aritmética de 8, 9 e 7 é %.2f\n", media);
        double media2 = (4+5+6)/3;
        System.out.printf("A média aritmética de 4, 5 e 6 é %.2f\n", media2);
        System.out.printf("A soma das duas médias é %.2f\n", media+media2);
        System.out.printf("A média das médias é %.2f", (media+media2)/2);
    }
    
    public static void ex3_reajuste() {
        Scanner scanner = new Scanner(System.in);
        double saldo;
        System.out.print("Digite seu saldo: ");
        saldo = scanner.nextInt();
        saldo+=saldo * 0.01;
        System.out.printf("Com reajuste, seu saldo resultou em R$%.2f", saldo);
    }
    
    public static void ex4_ipi() {
        Scanner scanner = new Scanner(System.in);
        Peca peca1 = new Peca();
        Peca peca2 = new Peca();
        double ipi, formula;
        System.out.print("Digite a porcentagem do IPI: ");
        ipi = scanner.nextDouble();
        System.out.print("Digite o codigo da peca 1: ");
        peca1.codigo = scanner.nextInt();
        System.out.print("Digite o valor unitário da peca 1: ");
        peca1.valor = scanner.nextDouble();
        System.out.print("Digite a quantidade de peca 1: ");
        peca1.quantidade = scanner.nextInt();
        System.out.print("Digite o codigo da peca 2: ");
        peca2.codigo = scanner.nextInt();
        System.out.print("Digite o valor unitário da peca 2: ");
        peca2.valor = scanner.nextDouble();
        System.out.print("Digite a quantidade de peca 2: ");
        peca2.quantidade = scanner.nextInt();
        formula = (peca1.valor*peca1.quantidade + peca2.valor*peca2.quantidade)*(ipi/100 +1);
        System.out.printf("\nO valor total a ser pago é de R$%.2f\n", formula);
    }
    
    public static void ex5_salario(){
        Scanner scanner = new Scanner(System.in);
        double salariominimo, salariousuario;
        System.out.print("Digite o salário mínimo atual: ");
        salariominimo = scanner.nextDouble();
        System.out.print("Digite o seu salário: ");
        salariousuario = scanner.nextDouble();
        System.out.printf("\nVocê ganha %.2f salários mínimos.\n", salariousuario/salariominimo);
    }

    public static void ex6_antsuc(){
        Scanner scanner = new Scanner(System.in);
        int n;
        System.out.print("Digite um número inteiro: ");
        n = scanner.nextInt();
        System.out.printf("\nO antecessor de %d é %d e o seu sucessor é %d.\n", n, n-1, n+1);
    }

    public static void menu() {
        System.out.println("================");
        System.out.println(" MENU PRINCIPAL");
        System.out.println("================\n");
        System.out.println("Opções:");
        System.out.println("1. Exercício 1: Idade");
        System.out.println("2. Exercício 2: Média");
        System.out.println("3. Exercício 3: Saldo");
        System.out.println("4. Exercício 4: IPI");
        System.out.println("5. Exercício 5: Salário");
        System.out.println("6. Exercício 6: Antecessor/Sucessor");
        System.out.println("7. Sair do programa\n");
    }

    public static byte getOption(){
        Scanner scanner = new Scanner(System.in);
        byte option;
        do {
            option = 0;
            System.out.print("Digite o número da opção desejada: ");
            option = scanner.nextByte();
        } while (option < 1 | option > 7);
        return option;
    }
    
    public static void main(String[] args) {
        byte opcao;
        do {
            Main.menu();
            opcao = Main.getOption();
            System.out.println();
            switch (opcao) {
                case 1:
                    Main.ex1_idade();
                    break;
                case 2:
                    Main.ex2_media();
                    break;
                case 3:
                    Main.ex3_reajuste();
                    break;
                case 4:
                    Main.ex4_ipi();
                    break;
                case 5:
                    Main.ex5_salario();
                    break;
                case 6:
                    Main.ex6_antsuc();
                    break;
            }
            if (opcao != 7) System.out.println();
        } while (opcao != 7);
        System.out.println("Encerrando o programa...\n");
    }
}
