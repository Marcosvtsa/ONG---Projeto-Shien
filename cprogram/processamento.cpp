#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unicsul.h"

int main(int argc, char *argv[])
{
    char dt_proc[30] = {0};
    char hr_proc[30] = {0};
    char prox_dt[30] = {0};

    int codigo;
    float valor, vl_mdr, vl_cred;
    int metodo;

    if (argc != 4)
    {
        printf("Quantidade de argumentos invalida.\n");
        return 1;
    }

    codigo = atoi(argv[1]);
    valor = atof(argv[2]);
    metodo = atoi(argv[3]);

    
    get_data_hora(dt_proc, hr_proc);

    
    strcpy(prox_dt, dt_proc);

    
    switch (metodo)
    {
        case 0: 
            get_prox_data(dt_proc, 0, prox_dt);
            vl_mdr = 0.0;
            break;
            
        case 1: 
            get_prox_data(dt_proc, 1, prox_dt);
            vl_mdr = valor * 0.03; 
            break;
            
        case 2: 
            get_prox_data(dt_proc, 30, prox_dt);
            vl_mdr = valor * 0.05; 
            break;
            
        default:
            printf("Metodo invalido.\n");
            return 1;
    }
    
    
    vl_cred = valor - vl_mdr;
        
    printf("Data do proc: %s\n", dt_proc);
    printf("Hora do proc: %s\n", hr_proc);
    printf("Proxima data util: %s\n", prox_dt);

    printf("Codigo: %d\n", codigo);
    printf("Valor: %.2f\n", valor);
    printf("Metodo: %d\n", metodo);
    printf("MDR: %.2f\n", vl_mdr);
    printf("Credito: %.2f\n", vl_cred);

    
    printf("<h1>OBRIGADO PELO PAGAMENTO</h1>\n");
    grava_log(
        dt_proc,
        hr_proc,
        codigo,
        metodo,
        valor,
        vl_mdr,       
        vl_cred,     
        prox_dt
    );

    return 0;
}