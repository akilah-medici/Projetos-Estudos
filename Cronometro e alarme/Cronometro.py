from datetime import datetime, time
from time import sleep

while(1):
    hora_atual = datetime.now().time()
    print(f"Horario: {hora_atual.hour}:{hora_atual.minute}")
    sleep(1)
    
def set_Alarme(H,M):
    return time(H,M)

    





'''if hora_atual.hour == alarme.hour and hora_atual.minute == alarme.minute:
        print("ACORDAAAAAAAAA")
        break
'''