import java.util.Scanner;

public class Main {
    public void idade() {
        Scanner scanner = new Scanner(System.in);
        int anos, meses, dias;
        System.out.println("Digite sua idade em anos, meses e dias:");
        anos = scanner.nextInt();
        meses = scanner.nextInt();
        dias = scanner.nextInt();
        anos*=365;
        meses*=30;
        dias+=anos+meses;
        System.out.println("Você tem "+dias+" dias de idade!");
    }
    public void media() {
        double media = (8+9+7)/3;
        System.out.println(media);
        double media2 = (4+5+6)/3;
        System.out.println(media2);
        System.out.println((media+media2)/2);
    }
    public void reajuste() {
        Scanner scanner = new Scanner(System.in);
        double saldo;
        System.out.println("Digite seu saldo:");
        saldo = scanner.nextInt();
        saldo+=saldo * 0.01;
        System.out.println("Com reajuste, seu saldo resultou em R$"+saldo);
    }
    public void ipi() {
        Scanner scanner = new Scanner(System.in);
        Peca peca1 = new Peca();
        Peca peca2 = new Peca();
        double ipi, formula;
        System.out.println("Digite a porcentagem do IPI:");
        ipi = scanner.nextDouble();
        System.out.println("Digite o codigo da peca 1:");
        peca1.codigo = scanner.nextInt();
        System.out.println("Digite o valor unitário da peca 1:");
        peca1.valor = scanner.nextDouble();
        System.out.println("Digite a quantidade de peca 1:");
        peca1.quantidade = scanner.nextInt();
        System.out.println("Digite o codigo da peca 2:");
        peca2.codigo = scanner.nextInt();
        System.out.println("Digite o valor unitário da peca 2:");
        peca2.valor = scanner.nextDouble();
        System.out.println("Digite a quantidade de peca 2:");
        peca2.quantidade = scanner.nextInt();
        formula = (peca1.valor*peca1.quantidade + peca2.valor*peca2.quantidade)*(ipi/100 +1);
        System.out.printf("O valor total a ser pago é de R$%.2f", formula);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double salariominimo, salariousuario;
        System.out.println("Digite o salário mínimo atual:");
        salariominimo = scanner.nextDouble();
        System.out.println("Digite o seu salário:");
        salariousuario = scanner.nextDouble();
        System.out.printf("Você ganha %.2f salários mínimos.", salariousuario/salariominimo);
    }
}
