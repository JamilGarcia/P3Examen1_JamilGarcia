#include <iostream>
#include "PC.hpp"
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<PC *> listaPC;
    char SalidaMenu = 'n';
    while (SalidaMenu == 'n')
    {
        
        int opcion;
        cout << "Menu: " << endl
             << "1) Crear PC" << endl
             << "2) CMD" << endl
             << "Opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            string DirecIp, Usuario, MascaraIP, HostName;
            cout << "Ingrese lo siguiente: "
                 << "Usuario: ";
            cin >> Usuario;
            cout << "Direccion IP: ";
            cin >> DirecIp;
            cout << "Mascara IP: ";
            cin >> MascaraIP;
            cout << "HostName: ";
            cin >> HostName;
            //PC *NPC = new PC(Usuario, DirecIp, MascaraIP, HostName);
            listaPC.push_back(new PC(Usuario, DirecIp, MascaraIP, HostName));
        }
        break;
        case 2:
        {
            if (listaPC.empty())
            {
                cout << "Debe Crear una pc primero" <<endl;
                break;
            }
            int opcionUs;
            string comando;
            cout << "PC's:" << endl;

            for (int i = 0; i < listaPC.size(); i++)
            {
                cout << i << ") " << listaPC.at(i)->getUsuario() <<endl;
            }
                cout << endl;
            cout << "Numero de Usuario: ";
            cin >> opcionUs;
            bool activarterminal = true;
            while (activarterminal == true)
            {
                string UsuarioActivo = listaPC.at(opcionUs)->getUsuario() + "#";
                PC *PCActiva = listaPC.at(opcionUs);
                cout << UsuarioActivo;
                cin >> comando;
                if (comando == "show")
                {   
                    cout <<endl; 
                    //cout << "entra show";
                    cout << "       IP: " << PCActiva->getDirecIP() <<endl
                        << "        NetMask: " << PCActiva->getMascaraIP() << endl; 
                }
                else if (comando == "exit")
                {   
                    //cout << "entra exit";
                    activarterminal = false;
                    break;
                }
                else
                {
                    //cout << "entra ping";
                    /*
                bool revisarComando = true; 
                string tempIP, tempString = "ping_"; 
                for (int i = 0; i < comando.length(); i++)
                {
                    if (comando[i] == tempString[i]){
                        
                    } else {
                        revisarComando = false;
                    }
                }

                if (revisarComando == true){

                }else {
                    cout << "No existe ningun comando llamado asi"
                }
                */
                    string tempIP;
                    for (int i = 5; i < comando.length(); i++)
                    {
                        tempIP += comando[i];
                    }
                    PCActiva->Ping(tempIP, listaPC);
                }
            }
        }
        break;
        case 0:
        {
            /* code */
        }
        break;

        default:
            break;
        }
    }
}