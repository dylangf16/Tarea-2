#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Server.h"
#include <string>
#include <fstream>
using namespace std;

std::string buscar_Prueba(int init, int end, std::string num_a_buscar){
    std::ifstream archivo("/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/hash.txt");
    std::string linea;
    std::string texto;
    int i = 0;
    while (i < 500){
        getline(archivo,linea);
        while (end = linea.find("-", init), end >=0){
            if(linea.substr(init, end - init) == num_a_buscar){
                init = end + 1;
                return linea.substr(init, end - init);
            }
            i++;
            getline(archivo,linea);
        }
        i++;
        getline(archivo,linea);
    }
    return "Fallido";
}

TEST(PruebasServer, DesgloseComando){
    std::string commando = "COMMAND-1-2-3-0";
    EXPECT_TRUE("1" == Server(commando));
}

TEST(PruebasServer, Commando_IMG){
    std::string commando = "IMG-1-0-0-0";
    cout << buscar_Prueba(0,0,"1") << endl;
    EXPECT_TRUE(buscar_Prueba(0,0,"1") == Server(commando));
}

TEST(PruebasServer, Commando_MEMORIA){
    std::string commando = "Matrix_mem-1-2-3-0";
    EXPECT_TRUE("False" == Server(commando));
}

TEST(PruebasServer, Commando_START){
    std::string commando = "Start-0-0-0-0";
    EXPECT_TRUE("Terminado" == Server(commando));
}

TEST(PruebasServer, Commando_MIX){
    std::string commando = "Mix-0-0-0-0";
    EXPECT_TRUE("Terminado" == Server(commando));
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
