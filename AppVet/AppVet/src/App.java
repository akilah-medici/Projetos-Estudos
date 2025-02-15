// função add paciente
// menu
// quando paciente é criado insere data da criação da ficha e entradas de atendimentos

public class App {
    public static void main(String[] args) {
        ListaPacientes lista1 = new ListaPacientes();
        Paciente p1 = new Paciente("gui",1,10,"cao","labrador");
        Paciente p2 = new Paciente("gui2",12,19,"felino","gato persa");
        Paciente p3 = new Paciente("gui3",13,18,"ave","papagaio australiano");
        Paciente p4 = new Paciente("gui4",14,17,"reptil","lagartixa do mato");
        Paciente p5 = new Paciente("gui5",15,16,"anfibio","sapo boi");
        lista1.addPaciente(p1);
        lista1.addPaciente(p2);
        lista1.addPaciente(p3);
        lista1.addPaciente(p4);
        lista1.addPaciente(p5);
        
        for(int i = 0; i < lista1.getPacientes().size(); i++){
            System.out.println(lista1.getPacientes().get(i));
        }
        
    }
}
