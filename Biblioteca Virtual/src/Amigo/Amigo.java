package Amigo;

public class Amigo implements Comparable<Amigo>{
	
	private int idAmigo;
	private String nome;
	private String celular;

	public Amigo(int idAmigo, String nome, String celular) {
		super();
		this.idAmigo = idAmigo;
		this.nome = nome;
		this.celular = celular;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nomeAmigo) {
		this.nome = nomeAmigo;
	}

	public String getCelular() {
		return celular;
	}

	public int getIdAmigo() {
		return idAmigo;
	}

	public void setIdAmigo(int idAmigo) {
		this.idAmigo = idAmigo;
	}
	public void setCelular(String celular) {
		this.celular = celular;
	}

	@Override
	public int compareTo(Amigo outroAmigo) {
		return Integer.compare(this.idAmigo, outroAmigo.idAmigo);
	}
	@Override
	public String toString() {
		return "Amigo [idAmigo =" + idAmigo + ", nome =" + nome + "]";
	}

}
