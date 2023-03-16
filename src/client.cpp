// #include "../lib/json-develop/include/nlohmann/json.hpp"
#include "../lib/json.hpp"
#include <iostream>
#include <fstream>
#include <string>

using std::string;
using json = nlohmann::json;

string username = "root";
string password = "root";
string idUser = "1";

bool connexionBDD(string name, string pass){

    if(username==name && password==pass){
        std::cout << "Login success" << std::endl;
        return true;

    }
    else{
        std::cout << "Login failed" << std::endl;
        return false;
    }
    
}

void createJsonFile(){
    std::cout << "Create json file :" << std::endl;
    std::ifstream file("../data/"+idUser+".json");
}

int main(int argc, char *argv[]){
    
    string name;
    string pass;

    // Connexion
    std::cout << "Username:" << std::endl;
    std::cin >> name;

    std::cout << "Password:" << std::endl;
    std::cin >> pass;

    if(connexionBDD(name, pass)){
        createJsonFile();



    }
    
    return 0;
}
// Database 

// Tables


// std::ofstream file(name+".json");