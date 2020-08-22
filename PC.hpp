#include <iostream>
#include <string>
#include <vector>
#pragma once
using namespace std;
class PC
{
private:
    string Usuario;
    string DirecIP;
    string MascaraIP;
    string HostName;

public:
    PC(string usuario, string direcIP, string mascaraip, string hostname)
    {
        Usuario = usuario;
        DirecIP = direcIP;
        MascaraIP = mascaraip;
        HostName = hostname;
    }

    void Ping(string IP, vector<PC *> listaPC)
    {
        bool existeIP = false;
        for (int i = 0; i < listaPC.size(); i++)
        {
            if (listaPC.at(i)->getDirecIP() == IP)
            {
                existeIP = true;
            }
        }
        int DecidirMensaje = 3;

        if (existeIP == true)
        {
            int contMascara;
            string BinHostIP, BinOtraIP, BinMascara;
            BinHostIP = PasarBinario(DirecIP);
            BinOtraIP = PasarBinario(IP);
            BinMascara = PasarBinario(MascaraIP);
            //cout << BinHostIP << " y " << BinOtraIP;
            for (int i = 0; i < BinMascara.length(); i++)
            {
                if (BinMascara[i] == '1')
                {
                    contMascara += 1;
                }
            }
            bool Correcto = true;
            for (int i = 0; i < contMascara; i++)
            {
                if (Correcto == true)
                {
                    if (BinHostIP[i] == BinOtraIP[i])
                    {
                        Correcto = true;
                    }
                    else
                    {
                        //cout << BinHostIP[i] << " != " << BinOtraIP[i];
                        Correcto = false;
                    }
                }
            }
            if (Correcto == true)
            {
                DecidirMensaje = 1;
            }
            else
            {
                DecidirMensaje = 2;
            }
        }

        switch (DecidirMensaje)
        {
        case 1: //Mensaje Conectado

        {
            cout << endl;
            cout << "Pinging to " << IP << " with 32 bytes of data: " << endl
                 << "Reply from " << IP << ": bytes=32 time 37ms TTL=46" << endl
                 << "Reply from " << IP << ": bytes=32 time 37ms TTL=46" << endl
                 << "Reply from " << IP << ": bytes=32 time 37ms TTL=46" << endl
                 << "Reply from " << IP << ": bytes=32 time 37ms TTL=46" << endl
                 << endl
                 << "Ping statistics for " << IP << ": " << endl
                 << "   Packets: Sent = 4, Recieved = 4, Lost = 0 (0% loss)" << endl
                 << endl;
        }
        break;
        case 2: //Mensaje Fuera de Alcance
        {
            cout << endl;
            cout << "Pinging to " << IP << " with 32 bytes of data: " << endl
                 << "Reply from " << IP << ": Destination host unreachable" << endl
                 << "Reply from " << IP << ": Destination host unreachable" << endl
                 << "Reply from " << IP << ": Destination host unreachable" << endl
                 << "Reply from " << IP << ": Destination host unreachable" << endl
                 << endl
                 << "Ping statistics for " << IP << ": " << endl
                 << "   Packets: Sent = 4, Recieved = 4, Lost = 0 (0% loss)" << endl
                 << endl;
        }
        break;
        case 3: //Mensaje PC No encontrada
        {
            cout << endl;
            cout << "Pinging to " << IP << "with 32 bytes of data: " << endl
                 << "Request timed out" << endl
                 << "Request timed out" << endl
                 << "Request timed out" << endl
                 << "Request timed out" << endl
                 << endl
                 << "Ping statistics for " << IP << ": " << endl
                 << "   Packets: Sent = 4, Recieved = 0, Lost = 4 (100% loss)" << endl
                 << endl;
        }
        break;

        default:
            break;
        }
    }

    int convertir(int IP)
    {
        int binario = 0, posicion = 1;
        while (IP > 0)
        {
            binario = binario + (IP % 2) * posicion;
            IP /= 2;
            posicion *= 10;
        }
        return binario;
    }

    string PasarBinario(string numero)
    {

        int tempNum;
        string finalNum, tempString;
        for (int i = 0; i < numero.length(); i++)
        {
            if (numero[i] == '.')
            {
            }
            else if (numero[i + 1] == '.' || numero[i + 1] == NULL)
            {
                tempString += numero[i];
                tempNum = stoi(tempString);
                tempNum = convertir(tempNum);
                string PaLosZeros = std::to_string(tempNum);
                while (PaLosZeros.length() <8){
                    PaLosZeros.insert(0,"0");
                }
                finalNum += PaLosZeros;
                finalNum = finalNum + ".";
                tempNum = 0;
                tempString = "";
            }
            else
            {
                tempString += numero[i];
            }
        }
        while (finalNum.length() < 8)
        {
            finalNum.insert(0, "0");
        }
        //Conectar abajo para ver los binarios
        //cout << "binario: " << finalNum;
        return finalNum;
    }

    //settter & Getters
    void setUsuario(string Usuario)
    {
        this->Usuario = Usuario;
    }

    string getUsuario()
    {
        return Usuario;
    }

    void setDirecIP(string DirecIP)
    {
        this->DirecIP = DirecIP;
    }

    string getDirecIP()
    {
        return DirecIP;
    }

    void setMascaraIP(string MascaraIP)
    {
        this->MascaraIP = MascaraIP;
    }

    string getMascaraIP()
    {
        return MascaraIP;
    }

    void setHostName(string HostName)
    {
        this->HostName = HostName;
    }

    string getHostName()
    {
        return HostName;
    }
};
