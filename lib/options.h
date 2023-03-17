#include <iostream>
#include <string>
#include <vector>
#include "database.hpp"
#include "table.hpp"

struct User {
    std::string id;
    std::string name;
    std::string password;
};

class Options{
    private:
        std::string id_user;
        std::vector<std::string> short_flag;
        
        
        std::string long_flag[7] = {"--login", "--username", "--password", "--format", "--version", "--sql", "--help"};

        std::string userId;
        std::string userName;
        std::string userPassword; 

        void (Options::*options_function[7])(std::string str) = {&Options::case_login, &Options::case_username, &Options::case_password, &Options::case_format, &Options::case_version, &Options::case_sql, &Options::case_help};

    public:
        void case_version(std::string str){
            std::cout << "Usage : sequel [-u|--username] <username> [-p|--password] <password> <options>" << std::endl << std::endl
                      << "Options :" << std::endl 
                      << "[-h|--help] : Display help" << std::endl
                      << "[-l|--login] : Check if credentials are valid" << std::endl
                      << "[-f|--format] <sql|csv|visual> : Choose format of return'"<< std::endl
                      << "[-s|--sql] <query> : Send a query to the DB" << std::endl;
        };
        void case_format(std::string str){};
        void case_help(std::string str){};
        void case_login(std::string str){};
        void case_username(std::string str){
            userName = str;
        };
        void case_password(std::string str){
            userPassword = str;
        };
        void case_sql(std::string str){
            // std::string delimiter = " ";
            // size_t pos = 0;
            // std::string token;
    
            // std::vector<std::string> query;

            // while ((pos = str.find(delimiter)) != std::string::npos) {
            //     token = str.substr(0, pos);
            //     std::cout << token << std::endl;
            //     query.push_back(token);
            //     str.erase(0, pos + delimiter.length());
            // }
            // query.push_back(str);

            // switch (query.at(0)){
            //     case "create":
            //         if(query.at(1)== "table"){
            //             table mytable();
            //         }
            //         break;
            //     case "delete":
            //         break;
            //     case "show":
            //         break;
            //     case "insert" :
            //         break;
            //     case "describe" :
            //         break;
            //     default :
            //         break; 
            // }
        };


        Options(std::string id):id_user(id){};
        
        // bool connexionBDD(string name, string pass){
        //     std::vector<User> users;

        //     std::ifstream readfile("../data/identifiants.txt");
        //     if (readfile.is_open()) {
        //         std::string line;
        //         while (std::getline(readfile, line)) {
        //             std::istringstream iss(line);
        //             User user;
        //             if (std::getline(iss, user.id, ',') &&
        //                 std::getline(iss, user.name, ',') &&
        //                 std::getline(iss, user.password, ',')) {
        //                 users.push_back(user);
        //             }
        //         }
        //     } else {
        //         std::cerr << "Error: Could not open file." << std::endl;
        //         return false;
        //     }
        //     for (const auto& user : users) {
        //         // std::cout << user.id << "," << user.name << "," << user.password << "\n";
        //         if(user.name==name && user.password==pass){
        //             userId = user.id;
        //             userName = user.name;
        //             userPassword = user.password;
        //             std::cout << "Login success" << std::endl;
        //             return true;
        //         }
        //     }
        //     std::cout << "Login failed" << std::endl;
        //     return false;
        // };

        void parse_args(){
            //short_flag.push_back("-l","-u","-p","-f","-v","-s","-h");
            //size_t i = 0;
            std::cout << "ok" << std::end;

            // do{
            //     for(size_t short_increment=0; short_increment < short_flag.size(); short_increment++){
            //         std::cout << "ok" << std::end;
            //     }
            //     i++;
            // }
            // while(argv[i]!="");

        };
};
