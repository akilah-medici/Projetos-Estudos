public class Paciente {
    //nome
    //idade
    //peso
    //especie
    //raça
    private String nome;
    private int idade;
    private int peso;
    private String especie;
    private String raca;
    

    public Paciente(String nome,int idade, int peso, String especie, String raca){
        this.nome = nome;
        this.idade = idade;
        this.peso = peso;
        this.especie = especie;
        this.raca = raca;
    }


    //getter's setter's
    public String getNome(){
        return nome;
    }
    public int getIdade(){
        return idade;
    }
    public int getPeso(){
        return peso;
    }
    public String getEspecie(){
        return especie;
    }
    public String getRaca(){
        return raca;
    }
    @Override
    public String toString() {
        return "Nome: "+nome+", Idade(Meses): "+idade+", Peso(Kg): "+peso+", Especie: "+especie+", Raça: "+raca;
    }
}
