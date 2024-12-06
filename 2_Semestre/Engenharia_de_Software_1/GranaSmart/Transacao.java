import java.util.Date;

public class Transacao {
    private String id;
    public String autor, destinatario, tipo, moeda;
    public double valor;
    public Date data;

    Transacao (String id) {
        this.id = id;
    }

    Transacao (double valor, Date data, String autor, String destinatario, String tipo, String moeda) {
        this.valor = valor;
        this.data = data;
        this.autor = autor;
        this.destinatario = destinatario;
        this.tipo = tipo;
        this.moeda = moeda;
    }

    public String consultarID() {
        return id;
    }
}