#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../lib/json.hpp"
#include "../lib/column.hpp"
#include "../lib/options.h"


using std::string;
using nlohmann::json;

string userId;
string userName;
string userPassword;

bool connexionBDD(string name, string pass){
    std::vector<User> users;

    std::ifstream readfile("../data/identifiants.txt");
    if (readfile.is_open()) {
        std::string line;
        while (std::getline(readfile, line)) {
            std::istringstream iss(line);
            User user;
            if (std::getline(iss, user.id, ',') &&
                std::getline(iss, user.name, ',') &&
                std::getline(iss, user.password, ',')) {
                users.push_back(user);
            }
        }
    } else {
        std::cerr << "Error: Could not open file." << std::endl;
        return false;
    }
    for (const auto& user : users) {
        // std::cout << user.id << "," << user.name << "," << user.password << "\n";
        if(user.name==name && user.password==pass){
            userId = user.id;
            userName = user.name;
            userPassword = user.password;
            std::cout << "Login success" << std::endl;
            return true;
        }
    }
    std::cout << "Login failed" << std::endl;
    return false;
}



int main(int argc, char *argv[]){
    
    string name;
    string pass;
    string nameBDD;
    string nameTable;
    string nameColumn;

    Options o;

    o.command(argc,argv);



    // Connexion
    // std::cout << "Username:";
    // std::cin >> name;
    // std::cout << std::endl;
    // std::cout << "Password:";
    // std::cin >> pass;
    // std::cout << std::endl;


    // if(connexionBDD(name, pass)){
        // database myfileBDD(userId);

        // std::cout << "nameDatabase - create: " << std::endl;
        // std::cin >> nameBDD;
        // myfileBDD.create(nameBDD);

        // std::cout << "nameDatabase - read: " << std::endl;
        // std::cin >> nameBDD;
        // myfileBDD.read(nameBDD);

        // std::cout << "nameDatabase - remove: " << std::endl;
        // std::cin >> nameBDD;
        // myfileBDD.remove(nameBDD);

        // std::cout << "nameDatabase - table: " << std::endl;
        // std::cin >> nameBDD;
        // table myfileTable(userId,nameBDD);

        // std::cout << "nameTable - create: " << std::endl;
        // std::cin >> nameTable;
        // myfileTable.create(nameTable);

        // std::cout << "nameTable - read: " << std::endl;
        // std::cin >> nameTable;
        // myfileTable.read(nameTable);

        // std::cout << "nameTable - remove: " << std::endl;
        // std::cin >> nameTable;
        // myfileTable.remove(nameTable);

    //     std::cout << "nameDatabase - column: ";
    //     std::cin >> nameBDD;
    //     std::cout << std::endl;
    //     std::cout << "nameTable - column: " << std::endl;
    //     std::cin >> nameTable;
    //     std::cout << std::endl;
    //     column myfileColumn(userId,nameBDD,nameTable);

    //     std::cout << "nameColumn - create: " << std::endl;
    //     std::cin >> nameColumn;
    //     myfileColumn.create(nameColumn);

    //     std::cout << "nameColumn - read: " << std::endl;
    //     std::cin >> nameColumn;
    //     myfileColumn.read(nameColumn);

    //     std::cout << "nameColumn - remove: " << std::endl;
    //     std::cin >> nameColumn;
    //     myfileColumn.remove(nameColumn);
    // }
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