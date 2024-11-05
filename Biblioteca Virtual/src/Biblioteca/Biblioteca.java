package Biblioteca;

import java.util.ArrayList;
import java.util.Collections;

public class Biblioteca{

	private String nome;
	private ArrayList<Livro> alLivros;
	private float investimento;
	// construtor cria alLivros, ArrayList que fica encapsulado na classe Biblioteca
	public Biblioteca(String nome) {
		this.nome = nome;
		this.alLivros = new ArrayList<Livro>();
		investimento = 0;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public ArrayList<Livro> getAlLivros() {
		return alLivros;
	}

	public void addAlLivros(String tit,String aut, float preco){
		int idLivro = this.alLivros.size() +1;
		Livro livro = new Livro(idLivro,tit,aut,preco);
		this.alLivros.add(livro);
		livro.setDispLivro(Disponibilidade.DISPONIVEL);
		System.out.println("O ID do livro é: "+idLivro);
	}
	public void addAlLivros(Livro livro){
		this.alLivros.add(livro);
	}

	public void ordenaLivros() {
		Collections.sort(alLivros); // Ordena a lista usando o compareTo() da classe Livro
	}
	public float getInvestimento() {
		return investimento;
	}
	public void setInvestimento(float investimento) {
		this.investimento = investimento;
	}
}
