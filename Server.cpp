//
// Created by dylan16 on 25/04/22.
//
#include "Server.h"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/Hashmap.cpp"
#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/matriz_dinamica.cpp"
#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/matriz.cpp"

using namespace std;
//Función principal que ejecuta el servidor
string Server(string comando_completo)
{
    // Create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
    {
        cerr << "Can't create a socket! Quitting" << endl;
        return "-1";
    }

    // Bind the ip address and port to a socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    bind(listening, (sockaddr*)&hint, sizeof(hint));

    // Tell Winsock the socket is for listening
    //listen(listening, SOMAXCONN);

    // Wait for a connection
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);

    //int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

    char host[NI_MAXHOST];      // Client's remote name
    char service[NI_MAXSERV];   // Service (i.e. port) the client is connect on

    //memset(host, 0, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
    //memset(service, 0, NI_MAXSERV);

    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
    {
        //cout << host << " connected on port " << service << endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        //cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }

    // Close listening socket
    close(listening);

    // While loop: accept and echo message back to client
    char buf[4096];
    string num;
    int valores;

    if (true)
    {
        memset(buf, 0, 4096);
        string command = "NULL";
        string val1 = "NULL";
        string val2 = "NULL";
        string val3 = "NULL";

        int init = 0;
        int end = 0;


        // Wait for client to send data
        //int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (valores == -1)
        {
            cerr << "Error in recv(). Quitting" << endl;
            //break;
        }

        if (valores == 0)
        {
            //cout << "Client disconnected " << endl;
            //break;
        }



        //Analizar y dividir string recibido
        //std::string linea = string(buf,0,bytesReceived);
        int conteo = 0;
        linea = comando_completo;
        while(end=linea.find("-", init), end >= 0){
            if (command == "NULL" & conteo == 0){
                command = linea.substr(init, end-init);
                init = end + 1;
            }
            if (val1 == "NULL" & conteo == 1){
                val1 = linea.substr(init, end-init);
                init = end + 1;
            }
            if (val2 == "NULL" & conteo == 2){
                val2 = linea.substr(init, end-init);
                init = end + 1;
            }
            if (val3 == "NULL" & conteo == 3){
                val3 = linea.substr(init, end-init);
                init = end + 1;
            }
            conteo +=1;
        }

        num = val1;

        //Ejecuta un comando según el primer valor del string recibido
        if(command == "IMG"){
            num = buscar(0,0,val1);
            //send(clientSocket, num.c_str(), num.size() + 1, 0);
            cout << "Desde servidor" << endl;
            cout << num << endl;
        }

        if(command == "Matrix_mem"){
            num = rellenarMatriz(stoi(val1),stoi(val2),val3);
            mostrar_matriz_disco(stoi(val1),stoi(val2));
            //send(clientSocket, num.c_str(), num.size() + 1, 0);
        }

        if(command == "Start"){
            generarMatriz();
            generarHash();
            num = "Terminado";
            //send(clientSocket, num.c_str(), num.size() + 1, 0);
        }
        if(command == "Mix"){
            revolverMatriz();
            num = "Terminado";
            //send(clientSocket, num.c_str(), num.size() + 1, 0);
        }
    }

    // Close the socket
    //close(clientSocket);

    return num;
}


