/*
Student Name: Alexander Rogers
Student NetID: abr241
Compiler Used: Visual Studio
Program Description: Program assignment 3
Assigned Sept 2020
*/

#include <sstream> 
#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "BST.h"

bool exit_fun(std::vector<std::string>& cmd_input)
{
    // exit function
    std::cout << "Exiting porgram\n";
    return true;

}
bool load_fun(std::vector<std::string>& cmd_input, std::vector<std::string>& cmd_output)
{
    // modified code from example at https://www.learncpp.com/cpp-tutorial/186-basic-file-io/

    std::ifstream inf{ cmd_input[0] }; //should contain the name of the file along with its . suffix
    std::stringstream ss; // repeat main
// error handling

    if (!inf)
    {
        std::cout << "\n";
        std::cout << "Error: file could not be accessed.\n";
        return false;
    }

    // parse files contents
    while (inf)
    {
        std::string strInput;
        std::getline(inf, strInput); //puts line in strInput
        if (!(strInput == ""))
        {
            cmd_output.push_back(strInput);
        }
    }

    return true;
}


int main()
{
    bool load_in_prog = false;
    bool finished_load = true;
    bool exit_program = false;
    std::cin; // declaring for getline
    std::string str_input;
    std::string cmd;
    std::vector<std::string> cmd_input;
    std::vector<std::string> cmd_output; // used for data output from loaded ext files
    BST user;
    BST ticket;
    
    
    


    do
    {

        cmd_input.clear();// resets program

        // modified code from example at https://www.learncpp.com/cpp-tutorial/56-do-while-statements/
        do
        {
            std::cout << "\nWelcome to Program 3: BST \n";
            std::cout << "Please use the following commands: \n \n";
            std::cout << "1) exit - exits the program\n";
            std::cout << "2) load <file> - parses .txt file\n";
            std::cout << "3) display <BST> in - displays bst in order\n";
            std::cout << "4) display <BST> pre - displays bst in preorder\n";
            std::cout << "5) display <BST> post - displays bst in postorder\n";
            std::cout << "6) new - deletes both BSTs and replaces them with empty BSTs\n";

            std::cout << "7) remove <user id> <ticket> - Removes the specified user id – ticket number pair from both BSTs. Should report failure if the pairing doesn’t exist.\n";
            std::cout << "8) find <user id> <ticket> - Searches the BSTs for the specified user id – ticket number pair and displays whether they were found or not.\n";
            std::cout << "9) add <user id> <ticket> - Inserts the specified user id – ticket number pair into both BSTs. Should report failure if the pairing exists.\n";
            std::cout << "10) save <BST> into <file> - saves the post order traversal of the specified BST into a text file named file.\n";
            std::cout << "****<ticket> is an integer. <BST> = {user, ticket}\n\n";


            std::getline(std::cin, str_input);
        } while (str_input == "");


        do
        {


            std::stringstream ss(str_input);



            if (load_in_prog)
            {
                // starts when load is in progress
                // starts parsing input text file should from this point onward. parses the input line back into the cmd_input
                cmd_input.clear();
                ss.str("");
                ss << cmd_output[0];
                cmd_output.erase(cmd_output.begin()); //pop off first line
            }


            // modified code from example at https://stackoverflow.com/questions/8046357/how-do-i-check-if-a-stringstream-variable-is-empty-null/36327567
            // adds each word from cmd invidually to a vector while the stringstream buffer is not equal to 0
            while (ss.rdbuf()->in_avail() != 0)
            {
                std::getline(ss, cmd, ' ');
                cmd_input.push_back(cmd);
            }

            // parsing input
            if (cmd_input[0] == "exit")
            {
                cmd_input.erase(cmd_input.begin()); //pop off first command
                exit_program = exit_fun(cmd_input);
                
            }
            else if (cmd_input[0] == "load")
            {
                cmd_input.erase(cmd_input.begin()); //pop off first command
                //  text.txt left
                if (cmd_input.size() == 1)
                {
                    load_fun(cmd_input, cmd_output);
                    cmd_input.clear();
                    load_in_prog = true; // important for progam flow
                    finished_load = false;//imp
                }
                else
                {
                    std::cout << "\nLoad error\n";
                }
                cmd_input.clear();
            }
            else if (cmd_input[0] == "find")
            {

            }
            else if (cmd_input[0] == "remove")
            {
                cmd_input.erase(cmd_input.begin());  //pop off next command

                if (cmd_input.size() == 1)
                {
                    
                }
               

                cmd_input.clear();


            }
            else if (cmd_input[0] == "display")
            {
                std::stringstream display;
                cmd_input.erase(cmd_input.begin()); //pop off first command
                std::cout << "\n";
                // <BST> [0] in [1]

                if (cmd_input[1] == "in")
                {
                    if (cmd_input[0] == "user")
                    {
                        user.inOrder(display);
                    }
                    else if (cmd_input[0] == "ticket")
                    {
                        ticket.inOrder(display);
                    }

                   
                }
                else if (cmd_input[1] == "pre")
                {
                    if (cmd_input[0] == "user")
                    {
                        user.preOrder(display);
                    }
                    else if (cmd_input[0] == "ticket")
                    {
                        ticket.preOrder(display);
                    }

                }
                else  // POST
                {
                    if (cmd_input[0] == "user")
                    {
                        user.postOrder(display);
                    }
                    else if (cmd_input[0] == "ticket")
                    {
                        user.postOrder(display);
                    }

                }
                
                std::cout << display.str() << "\n";

                cmd_input.clear();

            }
            else if (cmd_input[0] == "new")
            {

                cmd_input.erase(cmd_input.begin()); //pop off first command

                user.~BST();
                ticket.~BST();   // DESTROY

            }
            else if (cmd_input[0] == "add")
            {
                cmd_input.erase(cmd_input.begin()); //pop off first command
                //<card>[0] from [1] <puzzle> [2]
               
            }
            else
            {
                std::cout << "Undefined CALLED \n";
            }


            finished_load = cmd_output.empty();


            if (finished_load)
            {
                load_in_prog = false;
            }

            // clear cmd_input at begining of program
        } while (finished_load == false);



    } while (exit_program == false);
}
