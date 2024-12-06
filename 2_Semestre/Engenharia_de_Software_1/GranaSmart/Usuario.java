import java.util.Date;

public class Usuario extends Entidade {
    private String senha;
    private int idade;
    private Date dataNascimento;

    Usuario() {}

    Usuario (String nome, String cpf_cnpj, String email, String telefone) {
        this.nome = nome;
        this.email = email;
        this.telefone = telefone;

        if (cpf_cnpj.length() == 14) cpf = cpf_cnpj;
        else cnpj = cpf_cnpj;
    }
}
