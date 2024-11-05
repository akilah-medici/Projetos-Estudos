package Emprestimo;
import Amigo.ListaAmigos;

import java.util.ArrayList;

public class ListaEmprestimos {

	private ArrayList<Emprestimo> alEmprestimos;

	// construtor cria alEmprestimos, ArrayList que fica encapsulado na classe ListaEmprestimos
	public ListaEmprestimos() {
		super();
		this.alEmprestimos = new ArrayList<Emprestimo>();
	}
	public void addEmprestimo(Emprestimo emp){

		this.alEmprestimos.add(emp);
	}
	public ArrayList<Emprestimo> getAlEmprestimos() {
		return alEmprestimos;
	}

	@Override
	public String toString() {
		return "ListaEmprestimos{" +
				"alEmprestimos=" + alEmprestimos +
				'}';
	}
}
