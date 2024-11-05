package Emprestimo;
import java.time.LocalDate;

import Amigo.Amigo;
import Biblioteca.Disponibilidade;
import Biblioteca.Livro;

import java.util.Collections;

public class Emprestimo implements Comparable<Emprestimo> {

	private int idAmigo;
	private int idLivro;
	private LocalDate dataEmprestimo;
	private LocalDate dataDevolucao;

	public Emprestimo(int idAmigo,int idLivro,LocalDate dataEmprestimo,LocalDate dataDevolucao){
		this.idAmigo = idAmigo;
		this.idLivro = idLivro;
		this.dataEmprestimo = dataEmprestimo;
		this.dataDevolucao = dataDevolucao;
	}
	public Emprestimo(int idAmigo,int idLivro,LocalDate dataEmprestimo){
		this.idAmigo = idAmigo;
		this.idLivro = idLivro;
		this.dataEmprestimo = dataEmprestimo;

	}

	private Livro livro;
	private Amigo amigo;

	public void estadoLivro(){
		livro.setDispLivro(Disponibilidade.EMPRESTADO);
	}

	public int getIdAmigo() {
		return idAmigo;
	}

	public void setIdAmigo(int idAmigo) {
		this.idAmigo = idAmigo;
	}

	public int getIdLivro() {
		return idLivro;
	}

	public void setIdLivro(int idLivro) {
		this.idLivro = idLivro;
	}

	public LocalDate getDataEmprestimo() {
		return dataEmprestimo;
	}

	public void setDataEmprestimo(LocalDate dataEmprestimo) {
		this.dataEmprestimo = dataEmprestimo;
	}

	public LocalDate getDataDevolucao() {
		return dataDevolucao;
	}

	public void setDataDevolucao(LocalDate dataDevolucao) {
		this.dataDevolucao = dataDevolucao;
	}

	@Override
	public int compareTo(Emprestimo outroEmprestimo ) {
		// Comparando os ids dos amigos
		return Integer.compare(this.idAmigo,outroEmprestimo.getIdAmigo());
	}
	@Override
	public String toString() {
		return "Emprestimo{" +
				"idAmigo=" + idAmigo +
				", idLivro=" + idLivro +
				", dataEmprestimo=" + dataEmprestimo +
				", dataDevolucao=" + dataDevolucao +
				'}';
	}
}
