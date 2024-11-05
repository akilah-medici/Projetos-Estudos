package Biblioteca;

import java.util.ArrayList;

public class Livro implements Comparable<Livro> {
	private int idLivro;
	private String titulo;
	private String autor;
	private float preco;
	private Disponibilidade dispLivro;

	public Livro(int idLivro, String titulo, String autor, float preco) {
		this.idLivro = idLivro;
		this.titulo = titulo;
		this.autor = autor;
		this.preco = preco;
	}

	public Livro(int idLivro, String titulo, String autor, float preco, Disponibilidade dispLivro) {
		this.idLivro = idLivro;
		this.titulo = titulo;
		this.autor = autor;
		this.preco = preco;
		this.dispLivro = dispLivro;
	}

	public int getIdLivro() {
		return idLivro;
	}

	public void setIdLivro(int id) {
		this.idLivro = id;
	}

	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	public String getAutor() {
		return autor;
	}

	public void setAutor(String autor) {
		this.autor = autor;
	}

	public float getPreco() {
		return preco;
	}

	public void setPreco(float preco) {
		this.preco = preco;
	}
	// compareTo - compara atributos de um objeto


	public Disponibilidade getDispLivro() {
		return dispLivro;
	}

	public void setDispLivro(Disponibilidade dispLivro) {
		this.dispLivro = dispLivro;
	}

	@Override
	public int compareTo(Livro outroLivro) {
		// Comparar os títulos dos livros em ordem alfabética
		return this.titulo.compareTo(outroLivro.titulo);
	}

	@Override
	public String toString() {
		return "Livro[" +
				"idLivro = " + idLivro +
				", titulo = '" + titulo + '\'' +
				", autor = '" + autor + '\'' +
				", preco = " + preco +
				", dispLivro = " + dispLivro +
				']';
	}
}
