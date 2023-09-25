#include <stdio.h>
#include <header.h>

int copy(char *src, char *dst) {
    struct message m1;
    long client = 110;
    bool status = true;

    do {
        printf("Digite uma expressao: \n");
        fgets(m1.expressao, sizeof(m1.expressao), stdin);

        if (sscanf(m1.expressao, "%lf%c%lf", &m1.num1, &m1.operador, &m1.num2) == 3) {
            
            send (FILE_SERVER, &m1.expressao);
            receive (client, &m2.result);

            if (m2.msg = 0) {
                printf("Resultado: %.1lf\n", m2.result);
            }
            else {
                if (m2.msg == -1)
                {
                    printf("Erro: Divisao por zero!\n");
                }
                else if (m2.msg == -2) {
                    printf("Operador invalido!\n");
                }
            }

            status = false;
        }
        else {
            printf("Expressao invalida!\n");
            printf("Redigitar expressao seguindo o exeplo: 12+4!!!\n");
        }

    } while (status);
    
    return 0;
}