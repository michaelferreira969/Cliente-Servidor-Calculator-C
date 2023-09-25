/* Definições dos Clientes e  Servidores */
#define MAX_PATH 255
#define BUF_SIZE 1024
#define FILE_SERVER 243

/* Códigos de Erros */
#define OK 0
#define E_DIV_ZERO -1
#define E_OP_INV -2
#define E_IO -4

/* Definições do formato de mensagem */
struct message {
    char data[BUF_SIZE];
    char expressao[100];
    double num1;
    double num2;
    char operador;
    double result;
    int msg;
};