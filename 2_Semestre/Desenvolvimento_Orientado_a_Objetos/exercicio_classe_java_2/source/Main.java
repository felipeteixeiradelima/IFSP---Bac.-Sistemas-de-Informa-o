class Main {
    public static void main (String[] args) {
        Cao cao1 = new Cao("Demolidor", "Pincther", "au au au grrrgggrrrrrgrggrgggrgggrrrrrrrrrrrrrrr");
        Cao cao2 = new Cao("Fafá", "Dogue Alemão", "rooof rooof rooof");

        Pessoa pessoa1 = new Pessoa("Joao", 50, cao2);
        Pessoa pessoa2 = new Pessoa("Sabrino", 35, cao1);

        pessoa1.pedirPraCaoLatir();
        pessoa2.pedirPraCaoLatir();

        pessoa1.pet.latir();
        pessoa2.pet.latir();
    }
}
