// Prompt user for a Linux command 
// Create a new child process, fork(), and execute a command 
// If the user enters, exit the program should terminate

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    string lnxcmd;
    while (true) {
        // User Input
        cout << "Input Linux Command or press 'Enter' to quit" << endl;
        cout << "shell> ";
        getline(cin, lnxcmd); // Read the whole line including spaces

        // Check if the input is empty (just Enter is pressed)
        if (lnxcmd.empty()) {
            break; // Exit the loop if the input is empty
        }

        // Forking a Child Process
        pid_t pid = fork(); // Citation: Create Fork Processes

        if (pid == -1) {
            perror("fork failed");
            exit(1);
        } else if (pid == 0) {
            // Execute Command in Child Process
            // Citation: Child Process, Execvp
            vector<string> args;
            size_t pos = 0;
            while ((pos = lnxcmd.find(' ')) != string::npos) {
                args.push_back(lnxcmd.substr(0, pos));
                lnxcmd.erase(0, pos + 1);
            }
            args.push_back(lnxcmd.c_str());

            // Convert vector of strings to an array of C-style strings
            vector<char*> c_args;
            for (string& arg : args) {
                c_args.push_back(const_cast<char*>(arg.c_str())); //Citation: String to Char*
            }
            c_args.push_back(nullptr);  // The last element must be nullptr

            int status = execvp(c_args[0], c_args.data());

            if (status == -1) {
                perror("execvp failed");
                exit(1);
            }
        } else {
            // Wait for Child Process
            // Citation: Waitpid
            int status;
            if (waitpid(pid, &status, 0) == -1) {
                perror("waitpid failed");
                exit(1);
            }
        }
    }
    return 0;
}
