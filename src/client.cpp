#include "../lib/json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "../lib/database.h"

using std::string;
using nlohmann::json;

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

int main(int argc, char *argv[]){
    
    string name;
    string pass;
    string nameBDD;

    // Connexion
    std::cout << "Username:" << std::endl;
    std::cin >> name;

    std::cout << "Password:" << std::endl;
    std::cin >> pass;

    if(connexionBDD(name, pass)){
        database myfileBDD(idUser);

        std::cout << "nameDatabase: " << std::endl;
        std::cin >> nameBDD;

        myfileBDD.create(nameBDD);
    }
    return 0;
}











// Database 

// Tables

    // std::string username;
    // std::string password;
    // bool login = false;
    // for (int i = 1; i < argc; ++i) {
    //     if (strcmp(argv[i], "-u") == 0 && i + 1 < argc) {
    //         username = argv[i + 1];
    //         i++;
    //     } else if (strcmp(argv[i], "-p") == 0 && i + 1 < argc) {
    //         password = argv[i + 1];
    //         i++;
    //     } else if (strcmp(argv[i], "-l") == 0) {
    //         login = true;
    //     }
    // }
    // if (login && !username.empty() && !password.empty()) {
    //     std::cout << "Login success" << std::endl;
    // } else {
    //     std::cout << "Usage: mybdd -u username -p password -l" << std::endl;
    // }
    // return 0;

    // ou
    
    // std::string username;
    // std::string password;
    // bool login = false;
    // bool sql = false;
    // bool format = false;
    // for (int i = 1; i < argc; ++i) {
    //     if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
    //         std::cout << "Usage: mybdd [OPTIONS]\n"
    //                   << "  -h, --help          Display this help message and exit\n"
    //                   << "  -v, --version       Output version information and exit\n"
    //                   << "  -l, --login         Test login credentials\n"
    //                   << "  -u, --user <USER>   Username for login\n"
    //                   << "  -p, --password <PASSWORD>\n"
    //                   << "                      Password for login\n"
    //                   << "  -s, --sql           Enter SQL mode\n"
    //                   << "  -f, --format        Output format\n";
    //         return 0;
    //     } else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0) {
    //         std::cout << "mybdd version 1.0.0" << std::endl;
    //         return 0;
    //     } else if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--login") == 0) {
    //         login = true;
    //     } else if (strcmp(argv[i], "-u") == 0 && i + 1 < argc) {
    //         username = argv[i + 1];
    //         i++;
    //     } else if (strcmp(argv[i], "-p") == 0 && i + 1 < argc) {
    //         password = argv[i + 1];
    //         i++;
    //     } else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--sql") == 0) {
    //         sql = true;
    //     } else if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--format") == 0) {
    //         format = true;
    //     }
    // }
    // if (login && !username.empty() && !password.empty()) {
    //     std::cout << "Login success" << std::endl;
    // } else if (sql) {
    //     std::cout << "SQL mode" << std::endl;
    // } else if (format) {
    //     std::cout << "Output format" << std::endl;
    // } else {
    //     std::cout << "Usage: mybdd [OPTIONS]\n"
    //               << "Use -h or --help to display available options" << std::endl;
    // }
    // return 0;