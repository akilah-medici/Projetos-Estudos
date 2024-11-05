package Amigo;
import java.util.ArrayList;

public class ListaAmigos {

	private ArrayList<Amigo> alAmigos;
	
	// construtor cria alAmigos, ArrayList que fica encapsulado na classe ListaAmigos
	public ListaAmigos() {
		super();
		this.alAmigos = new ArrayList<Amigo>();
	}
	
	public int addAmigo (String nome, String celular) {
		int idAmigo = alAmigos.size() + 1; 
		Amigo amigo = new Amigo(idAmigo, nome,celular);
		alAmigos.add(amigo);
		System.out.println("O ID de amigo é: "+idAmigo);
		return idAmigo;
	}
	
	public int getListaAmigosSize(){
		return alAmigos.size();
	}

	public Amigo getAmigo(int i){
		return alAmigos.get(i);
	}

	@Override
	public String toString() {
		return "ListaAmigos{" +
				"alAmigos=" + alAmigos +
				'}';
	}
}
