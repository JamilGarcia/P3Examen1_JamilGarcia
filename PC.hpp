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
            else if (numero[i + 1] == '.')
            {
                tempString += numero[i];
                tempNum = stoi(tempString);
                if (tempNum > 0)
                {
                    while (tempNum > 0)
                    {
                        if (tempNum % 2 == 0)
                        {
                            finalNum = "0" + finalNum;
                        }
                        else
                        {
                            finalNum = "1" + finalNum;
                        }
                        tempNum = (int)tempNum / 2;
                    }
                }
                else if (tempNum == 0)
                {
                    finalNum = "0" + finalNum;
                }
                finalNum += ".";
            }
            else
            {
                tempString += numero[i];
            }
        }
        cout << "binario: " << finalNum;
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
