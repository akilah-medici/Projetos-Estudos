import org.jetbrains.annotations.NotNull;

import java.util.ArrayList;
import java.util.Scanner;
import static java.lang.Character.getNumericValue;
import static java.lang.Character.isDigit;
import java.io.*;

// criar inicializador de contatos
// criar meio de inserir contatos
// criar salvamento de contatos
//criar buscador de contatos
public class Main {
    private static Scanner teclado = new Scanner(System.in);
    private static ArrayList<Contato> lista = new ArrayList<Contato>();

    public static void main(String[] args) {
        int op = -1;



        while(op !=0 ){
            System.out.println(" -*-*-*-*-*-*-*-*-*-*-*-*-");
            System.out.println(" Menu dos Contatos ");
            System.out.println(" 1) Criar contato");
            System.out.println(" 2) Excluir contato");
            System.out.println(" 3) Lista de contatos");
            System.out.println(" 4) Salvar lista de contatos");
            System.out.println(" 5) Carregar lista de contatos");
            System.out.println(" 0) Sair do programa");
            System.out.println(" -*-*-*-*-*-*-*-*-*-*-*-*-");
            op= teclado.nextInt();
            teclado.nextLine();
            switch (op){
                case 1:
                    // chama função cria contato
                    lista.add(criaContato());
                    break;
                case 2:
                    break;
                case 3:
                    for(int i = 0;lista.size()>i;i++ ) {
                        System.out.println(lista.get(i));
                    }
                    break;
                case 4:
                    salvaContato(lista);

                case 5:
                    carregaContato(lista);
                default:
            }
        }
    }

    private static Contato criaContato(){
        System.out.println("\n--- Novo contato ---\n");
        System.out.print("    Nome do contato? ");
        String nome = teclado.nextLine();

        System.out.print("    Numero do contato? ");
        int numero = teclado.nextInt();
        while(Contato.digitNum(numero)!=8){
            System.out.print("Numero de digitos invalido! Digite outro numero: ");
            numero = teclado.nextInt();
        }

        System.out.print("    DDD do contato? ");
        int DDD = teclado.nextInt();
        while(Contato.digitNum(DDD)>3){
            System.out.print("Numero de digitos invalido! Digite outro DDD: ");
            DDD = teclado.nextInt();
        }

        Contato contato = new Contato(nome,numero,DDD);
        return contato;
    }
    private static void salvaContato(ArrayList l){
        try (FileOutputStream fos = new FileOutputStream("contatos.ctt");
             ObjectOutputStream oos = new ObjectOutputStream(fos)) {
            oos.writeObject(l);
            System.out.println("Array de objetos salvo em arquivo com sucesso!");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    private static void carregaContato(@NotNull ArrayList<Contato> l) {
        try (FileInputStream fis = new FileInputStream("contatos.ctt");
             ObjectInputStream ois = new ObjectInputStream(fis)) {
            l.clear();
            l.addAll((ArrayList<Contato>) ois.readObject());
            System.out.println("Lista de contatos carregada com sucesso!");
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}













/*      teste dos objetos
        Contato c1 = new Contato("jao",0,0);
        System.out.println("Seu nome: "+c1.getNome());
        System.out.println("Seu numero: "+c1.getNum());
        c1.setNum(1000);
        System.out.println("Seu numero: "+c1.getNum());
        c1.setNum(989040747);
        System.out.println("Seu numero: "+c1.getNum());
        System.out.println(c1.getDdd());
        c1.setDdd(1000);
        System.out.println("Seu DDD: "+c1.getDdd());
        c1.setDdd(41);
        System.out.println("Seu DDD: "+c1.getDdd());        */
