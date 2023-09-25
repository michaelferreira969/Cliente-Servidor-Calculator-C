#include <stdio.h>
#include <header.h>

void main (void) {
    struct message m1, m2;
    
    while (1) {
        receive (FILE_SERVER, &m1);

        switch (m1.operador) {
            case '+':
                m2.result = m1.num1 + m1.num2;
                break;
            case '-':
                m2.result = m1.num1 - m1.num2;
                break;
            case '*':
                m2.result = m1.num1 * m1.num2;
                break;
            case '/':
                if (m1.num2 != 0) {
                    m2.result = m1.num1 / m1.num2;
                } else {
                    m2.result = E_DIV_ZERO;
                    send(m2.result, &m2);
                }
                break;
            default:
                m2.result = E_OP_INV;
                send(m2.result, &m2);
        }

        m2.error = 0;
        send (m2.result, &m2); 
    }
}