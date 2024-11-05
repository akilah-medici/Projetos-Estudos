package Principal;

import java.time.LocalDate;

import java.util.Scanner;

import Amigo.*;
import Emprestimo.*;
import Biblioteca.*;

public class Principal {
	
	private static Biblioteca bib = new Biblioteca("Biblioteca Pessoal");

	private static ListaEmprestimos emprestimos = new ListaEmprestimos();
	private static ListaAmigos amigos = new ListaAmigos();

	private static Scanner teclado = new Scanner(System.in);

	public static int menu(){
		String[] m = {
				"#--------------------------------------------------#",
				"#    Bem Vindo a Sua Biblioteca Pessoal Virtual    #",
				"#--------------------------------------------------#",
				"# (0) Sair                                         #",
				"# (1) Cadastrar Livro                              #",
				"# (2) Cadastrar Amigo                              #",
				"# (3) Emprestar Livro                              #",
				"# (4) Devolver Livro Emprestado                    #",
				"# (5) Listar Empréstimos Atuais                    #",
				"# (6) Listar Histórico de Empréstimos              #",
				"# (7) Listar Livros da Biblioteca                  #",
				"# (8) Alterar Estado para Consulta Local           #",
				"#--------------------------------------------------#"
		};
		for(int i = 0; i <m.length;i++ ){
			System.out.println(m[i]);
		}
		System.out.print("Escolha uma opção: ");
		int op = teclado.nextInt();

		switch (op){
			case 0:
				return 1;
            case 1:
				cadastraLivro();
				break;
			case 2:
				cadastraAmigo();
				break;
			case 3:
				cadastraEmprestimo();
				break;
			case 4:
				devolverEmprestimo();
				break;
			case 5:
				listaEmprestimos();
				break;
			case 6:
				listaHistoricoEmprestimo();
				break;
			case 7:
				listaLivros();
				break;
			case 8:
				alteraConsultaLocal();
				break;
			default:
				System.out.println("Escolha uma das opções acima.");
				break;
		}
		return 0;
	}

	public static void cadastraLivro(){
		System.out.println("\n--- Cadastro de um novo Livro ---\n");
		teclado.nextLine();
		System.out.print("    Qual o titulo do livro? ");
		String tit = teclado.nextLine();
		System.out.print("    Qual o nome do autor? ");
		String aut = teclado.nextLine();
		System.out.print("    Qual o preço do livro? ");
		float preco = teclado.nextFloat();

		bib.addAlLivros(tit,aut,preco);
    }

	public static void cadastraAmigo(){
		System.out.println("\n--- Cadastro de amigo ---\n");
		teclado.nextLine();
		System.out.print("    Nome do amigo? ");
		String nome = teclado.nextLine();
		System.out.print("    Numero de telefone? ");
		String num = teclado.nextLine();

		amigos.addAmigo(nome,num);
	}

	public static void cadastraEmprestimo(){
		System.out.println("\n--- Novo empréstimo gerado ---\n");
		teclado.nextLine();
		System.out.print("    Qual o ID do amigo? ");
		int idAmigo = teclado.nextInt();
		System.out.print("    Qual o ID do livro? ");
		int idLivro = teclado.nextInt();

		LocalDate dataAtual= LocalDate.now();

		Emprestimo emprestimo = new Emprestimo(idAmigo,idLivro,dataAtual);

		for(int i = 0; i < bib.getAlLivros().size(); i++) {
			if (idLivro == bib.getAlLivros().get(i).getIdLivro()) {
				bib.getAlLivros().get(i).setDispLivro(Disponibilidade.EMPRESTADO);
			}
		}

		emprestimos.addEmprestimo(emprestimo);
	}

	public static void devolverEmprestimo(){
		System.out.println("\n--- Nova Devolução efetuada ---\n");
		teclado.nextLine();
		System.out.print("    Qual o id de Amigo que realizou a devolução? ");
		int idAmigo = teclado.nextInt();
		LocalDate dataDev = LocalDate.now();

		for(int i = 0; i<emprestimos.getAlEmprestimos().size();i++) {
			int id = emprestimos.getAlEmprestimos().get(i).getIdAmigo();// salva id de i
			if(id == idAmigo){
				emprestimos.getAlEmprestimos().get(i).setDataDevolucao(dataDev);
				for(int j = 0; j< bib.getAlLivros().size();j++){
					int idLivro = emprestimos.getAlEmprestimos().get(i).getIdLivro();
					if(idLivro == bib.getAlLivros().get(j).getIdLivro()){
						bib.getAlLivros().get(j).setDispLivro(Disponibilidade.DISPONIVEL);
					}
				}
			}
		}

		System.out.println("Livro devolvido com sucesso.");
	}

	public static void listaEmprestimos(){
		System.out.println("\n--- Lista de livros emprestado ---\n");;
		for(int i = 0; i< emprestimos.getAlEmprestimos().size();i++){
			if(bib.getAlLivros().get(i).getDispLivro() == Disponibilidade.EMPRESTADO){
					System.out.println(emprestimos.getAlEmprestimos().get(i));
			}
		}
	}

	public static void listaHistoricoEmprestimo(){
		for(int i  = 0; i<emprestimos.getAlEmprestimos().size();i++){
			System.out.println(emprestimos.getAlEmprestimos().get(i));
		}
	}

	public static void listaLivros(){
		System.out.println("\n--- lista de livros em ordem alfabetica---\n");
		bib.ordenaLivros();
		float total = 0;
		for(int i = 0; i<bib.getAlLivros().size();i++){
			System.out.println(bib.getAlLivros().get(i));
			total = total + bib.getAlLivros().get(i).getPreco();
		}

		System.out.println(" ");
		System.out.println("Total investido na biblioteca: " + total);
		System.out.println(" ");
	}
	public static void alteraConsultaLocal(){
		teclado.nextLine();
		int id = teclado.nextInt();
		System.out.println("\n--- Alterar para consulta local---\n");
		System.out.println("   Qual livro deseja alterar para consulta local? digite seu id: ");

		for(int i  = 0; i<bib.getAlLivros().size(); i++) {
			if (bib.getAlLivros().get(i).getIdLivro() == id){
				Disponibilidade disp = bib.getAlLivros().get(i).getDispLivro();
				if (disp == Disponibilidade.DISPONIVEL || disp == Disponibilidade.EMPRESTADO) {
					bib.getAlLivros().get(i).setDispLivro(Disponibilidade.CONSULTALOCAL);
					System.out.println("Estado de livro alterado com sucesso.");
				}
			}
		}
	}


	public static void main(String[] args) {
		int idAmigo;

		idAmigo = amigos.addAmigo("Fulano", "(41) 99876-5432");
		System.out.println("Adicionado com codigo " + idAmigo);

		idAmigo = amigos.addAmigo("Ciclano", "(47) 98123-2121");
		System.out.println("Adicionado com codigo " + idAmigo);

		Livro l1 = new Livro(1, "The Catcher in the Rye", "J.D. Salinger", 19.99f, Disponibilidade.DISPONIVEL);
		Livro l2 = new Livro(2, "To Kill a Mockingbird", "Harper Lee", 24.99f, Disponibilidade.DISPONIVEL);
		Livro l3 = new Livro(3, "1984", "George Orwell", 15.99f, Disponibilidade.DISPONIVEL);
		Livro l4 = new Livro(4, "Pride and Prejudice", "Jane Austen", 18.50f, Disponibilidade.DISPONIVEL);
		Livro l5 = new Livro(5, "The Great Gatsby", "F. Scott Fitzgerald", 22.30f, Disponibilidade.DISPONIVEL);
		Livro l6 = new Livro(6, "Moby Dick", "Herman Melville", 17.99f, Disponibilidade.EXTRAVIADO);
		Livro l7 = new Livro(7, "War and Peace", "Leo Tolstoy", 29.50f, Disponibilidade.DISPONIVEL);
		Livro l8 = new Livro(8, "The Hobbit", "J.R.R. Tolkien", 21.00f, Disponibilidade.DANIFICADO);
		Livro l9 = new Livro(9, "Brave New World", "Aldous Huxley", 16.99f, Disponibilidade.EXTRAVIADO);
		Livro l10 = new Livro(10, "Crime and Punishment", "Fyodor Dostoevsky", 25.99f, Disponibilidade.DISPONIVEL);
		bib.addAlLivros(l1);
		bib.addAlLivros(l2);
		bib.addAlLivros(l3);
		bib.addAlLivros(l4);
		bib.addAlLivros(l5);
		bib.addAlLivros(l6);
		bib.addAlLivros(l7);
		bib.addAlLivros(l8);
		bib.addAlLivros(l9);
		bib.addAlLivros(l10);

		for (int i =0; i < amigos.getListaAmigosSize(); i++) {
			Amigo amigo = amigos.getAmigo(i);
			System.out.println("Nome: " + amigo.getNome());
			System.out.println("Celular: " + amigo.getCelular());
		}
		while(true){
			int estado = menu();;
			if (estado == 1){
				break;
			}
		}
	}
}
