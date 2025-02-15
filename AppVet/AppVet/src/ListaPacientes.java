import java.util.ArrayList;

public class ListaPacientes {
    private ArrayList<Paciente> pacientes;
    public ListaPacientes(){
        this.pacientes = new ArrayList<Paciente>();
    }
    
    public ArrayList<Paciente> getPacientes() {
        return pacientes;
    }
    public void addPaciente(Paciente paciente){
        this.pacientes.add(paciente);
    }
}
