import java.util.Scanner;

public class Menu {
    private static final Scanner scanner = new Scanner(System.in);
    private static int opcao;

    private static int pegarOpcao() {
        int opcao_local = 0;

        do { 
            opcao_local = scanner.nextInt();
        } while (opcao_local < 1 & opcao_local > 9);

        scanner.nextLine();

        return opcao_local;
    }

    public static int principal() {
        System.out.println(
            """
            MENU PRINCIPAL

            Opções:
            1. Registrar
            2. Login
            3. Consultar saldo
            4. Cadastrar nova conta
            5. Pesquisar transação
            6. Editar transação
            7. Excluir transação
            8. Visualizar planilha
            9. Sair\n
            """
        );
        
        System.out.println("Escolha uma opção: ");
        opcao = pegarOpcao();

        return opcao;
    }
}