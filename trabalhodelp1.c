#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Biblioteca que permite usar os caracteres em pt-br
#include <math.h>

// Variáveis
float icms, pis, cofins, tarifa, consumo_total_setor, consumo_total, valor_total_setor, valor_total;
float pt_arc, qtshrs_arc, consumo_arc; // Seção Arcondicionados
float pt_comp, qtshrs_comp, consumo_comp; // Seção Computador
float pt_gela, qtshrs_gela, consumo_gela; // Seção geladeira
float pt_lamp, qtshrs_lamp, consumo_lamp; // Seção Lampada
float pt_tv, qtshrs_tv, consumo_tv; // Seção TV
float val_arc, val_comp, val_gela, val_lamp, val_tv; //Variáveis de valores
float icms_real, pis_real, cofins_real, valor_total_real;
char nomedosetor[50]; // Nome do setor
int qts_comp, qts_arc, qts_gela, dias_comp, dias_arc, dias_gela, qts_lamp, dias_lamp, qts_tv, dias_tv, i; // Área de quantidadem dias dos equipamentos



/*Legenda*/
    // qts =  quantidade total
    // pt = potência
    // qtshrs = quantidade de horas
    // val = valores

//Função Principal
int main (){
    icms = 0.27;
    pis = 0.0165;
    cofins = 0.0761;

    // Com a inserção desse comando, os valores reais serão representados agora com vígula
    setlocale(LC_ALL, "portuguese");

    printf("---------------------------------------------------------- \n");
    printf("Seja bem vindo ao simulador \n");
    printf("---------------------------------------------------------- \n");
    printf("Informe o preço da Tarifa Residencial de Baixa Tensão: \n");
    scanf("%f", &tarifa);

    /* printf("Informe o nome do setor:  \n");
    scanf("%s", &nomedosetor); */

    do {
        printf("Digite a quantidade de arcondicionados \n");
        scanf("%d", &qts_arc);

        if (qts_arc > 0){
            printf("Digite as seguintes informações \n");
            printf("Os dados são no mês respectivamente \n");
            printf("Potência \n");
            scanf("%f", &pt_arc);
            printf("Quantidade de Horas \n");
            scanf("%f", &qtshrs_arc);
            printf("Quantidade de dias \n");
            scanf("%d", &dias_arc);

            consumo_arc = (((qtshrs_arc*dias_arc)*pt_arc)*qts_arc)/1000;
            // OS CONSUMOS SERÃO DIVIDOS POR 1000 PARA FAZER A CONVERSÃO DE WATTS PARA KW
        }


        printf("Digite a quantidade de computadores \n");
        scanf("%d", &qts_comp);

        if (qts_comp > 0){
            printf("Digite as seguintes informações \n");
            printf("Os dados são no mês respectivamente \n");
            printf("Potência \n");
            scanf("%f", &pt_comp);
            printf("Quantidade de Horas \n");
            scanf("%f", &qtshrs_comp);
            printf("Quantidade de dias \n");
            scanf("%d", &dias_comp);

            consumo_comp = (((qtshrs_comp*dias_comp)*pt_comp)*qts_comp)/1000;
        }

        printf("Digite a quantidade de geladeiras \n");
        scanf("%d", &qts_gela);

        if (qts_gela > 0){
            printf("Digite as seguintes informações \n");
            printf("Os dados são no mês respectivamente \n");
            printf("Potência \n");
            scanf("%f", &pt_gela);
            printf("Quantidade de Horas \n");
            scanf("%f", &qtshrs_gela);
            printf("Quantidade de dias \n");
            scanf("%d", &dias_gela);

            consumo_gela = (((qtshrs_gela*dias_gela)*pt_gela)*qts_gela)/1000;
        }

        printf("Digite a quantidade de lampadas\n");
        scanf("%d", &qts_lamp);

        if (qts_lamp > 0){
            printf("Digite as seguintes informações \n");
            printf("Os dados são no mês respectivamente \n");
            printf("Potência \n");
            scanf("%f", &pt_lamp);
            printf("Quantidade de Horas \n");
            scanf("%f", &qtshrs_lamp);
            printf("Quantidade de dias \n");
            scanf("%d", &dias_lamp);

            consumo_lamp = (((qtshrs_lamp*dias_lamp)*pt_lamp)*qts_lamp)/1000;
        }

        printf("Digite a quantidade de TVS \n");
        scanf("%d", &qts_tv);

        if (qts_tv > 0){
            printf("Digite as seguintes informações \n");
            printf("Os dados são no mês respectivamente \n");
            printf("Potência \n");
            scanf("%f", &pt_tv);
            printf("Quantidade de Horas \n");
            scanf("%f", &qtshrs_tv);
            printf("Quantidade de dias \n");
            scanf("%d", &dias_tv);

            consumo_tv = (((qtshrs_tv*dias_tv)*pt_tv)*qts_tv)/1000;


        }

        // Seção de valores
        val_arc = consumo_arc*tarifa;
        val_comp = consumo_comp*tarifa;
        val_gela = consumo_gela*tarifa;
        val_lamp = consumo_lamp*tarifa;
        val_tv = consumo_tv*tarifa;


        consumo_total_setor = consumo_arc + consumo_comp + consumo_gela + consumo_lamp + consumo_tv;
        valor_total_setor = val_arc + val_comp + val_gela + val_lamp + val_tv;

        consumo_total += consumo_total_setor;
        valor_total += valor_total_setor;

        // Valor parcial
        printf("SETOR:\n");
        printf("O valor total gasto no setor foi %.2f R$ \n", valor_total_setor);
        printf("O consumo total no setor foi %.2f KWH \n", consumo_total_setor);


        printf("ATENÇÃO! \n");
        printf("Você deseja calcular outro setor? \n");
        printf("[1] para sim e [0] para não\n");
        scanf("%d", &i);

    } while (i != 0);


        icms_real = valor_total*icms;
        pis_real = valor_total*pis;
        cofins_real = valor_total*cofins;

        // Valor total
        valor_total_real = valor_total + icms_real + pis_real + cofins_real;
        printf("O valor total com a adição das taxas ICMS, PIS, COFINS é %.2f R$ \n", valor_total_real);
        printf("O Consumo total foi de %.2f KWH \n", consumo_total);

        system("pause");




    return 0;
}


