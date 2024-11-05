import java.io.Serializable;

public class Contato implements Serializable{
    private String nome;
    private int num;
    private int ddd;

    public Contato(String nome, int num, int ddd) {
        this.nome = nome;
        this.num = num;
        this.ddd = ddd;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getNum() {
        if(this.num == 0){
            System.out.println("Nenhum numero inserido ao sistema.");
        }
        return num;
    }

    public void setNum(int num) {
        int sizeNum = 0;
        float n = num;
        float s = 1;
        while(s >0.1){
            s = n /10;
            n = n /10;
            if(s >0.1) {
                sizeNum += 1;
            }
        }
        if(sizeNum<9){
            System.out.println("O numero a ser inserido deve conter 9 digitos o seu tem: "+sizeNum);
        }else if(sizeNum > 9){
            System.out.println("O numero a ser inserido deve conter 9 digitos o seu tem: "+sizeNum);
        }else{
            System.out.println("Numero cadastrado com sucesso!");
            this.num = num;
        }
    }

    public int getDdd() {
        if(this.num == 0){
            System.out.println("Nenhum DDD inserido ao sistema.");
        }
        return ddd;
    }

    public void setDdd(int ddd) {
        int sizeNum = 0;
        float n = ddd;
        float s = 1;
        while(s >0.1){
            s = n /10;
            n = n /10;
            if(s >0.1) {
                sizeNum += 1;
            }
        }
        if(sizeNum>3) {
            System.out.println("O DDD a ser inserido deve conter no maximo 3 digitos o seu tem: " + sizeNum);
        }else{
            System.out.println("DDD cadastrado com sucesso!");
            this.ddd = ddd;
        }
    }

    @Override
    public String toString() {
        return "Meu nome: " + nome;
    }


    public static int digitNum(int num){
        int sizeNum = 0;
        float n = num;
        float s = 1;
        while(s >0.1) {
            s = n / 10;
            n = n / 10;
            if (s > 0.1) {
                sizeNum += 1;
            }
        }
        return sizeNum;
    }
}
