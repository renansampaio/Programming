#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Insumo{
    char nome[20];
    int codigo;
    char tipo;
    float custo;
    
} insumo;

typedef struct Servico{
    char nome[30];
    int codigo_insumos[10];
    int qtd_insumos[10];
    
} servico;

void inserir_insumo(insumo *insumos, int n){
    
    char conf;
    char nome[20];
    int codigo;
    char tipo;
    float custo;
    int k;
    
    for(k = 0; k < n; k++){
        if(insumos[k].codigo == 0){
            
            printf("Qual o nome do insumo que voce quer adicionar?\n");
            setbuf(stdin, NULL);
            scanf("%[A-Z a-z]s", nome);
            
            
            printf("Qual o codigo do insumo?\n");
            scanf("%d", &codigo);
            
            
            printf("Qual o tipo do insumo? (H para Recursos Humanos ou M para Materiais)\n");
            scanf(" %c", &tipo);
            while (( tipo != 'H') && (tipo != 'M') && ( tipo != 'h') && (tipo != 'm')) {
                printf("Opcao inexistente, digite H para Recursos Humanos ou M para Materiais\n");
                scanf(" %c", &tipo);
            }
            
            printf("Qual o custo unitario do insumo?\n");
            scanf("%f", &custo);
            
            
            printf("Voce tem certeza que deseja inserir o insumo? (S para SIM e N para NAO) \n");
            scanf(" %c", &conf);
            
            if (conf == 'S'  || conf == 's') {
                strcpy(insumos[k].nome, nome);
                insumos[k].codigo = codigo;
                insumos[k].tipo = tipo;
                insumos[k].custo = custo;
                
                printf("Insumo inserido com sucesso!\n");
                break;
            }
            else {
                printf("Insumo nao inserido!\n");
                break;
            }
            
            
        }
    }
}

void excluir_insumo(insumo *insumos, int n){
    
    int cod, loop = 0;
    int i;
    printf("Qual o codigo do insumo que deseja excluir?\n");
    scanf("%d", &cod);
    
    
    for (i = 0; i < n; i++) {
        if (cod == insumos[i].codigo){
            strcpy(insumos[i].nome, "");
            insumos[i].codigo = 0;
            insumos[i].tipo = ' ';
            insumos[i].custo = 0;
            loop = 1;
        }
        
    }
    if(loop == 0){
        printf("Codigo de insumo nao encontrado!");
    }
    else {
        printf("Insumo excluido com sucesso!\n");
    }
    
}

void inserir_servico(servico *servicos, int m){
    
    int qtd, k, j, z;
    
    for(j = 0; j < m; j++){
        if(servicos[j].codigo_insumos[0] == 0){
            
            printf("Qual o nome do servico que voce quer adicionar?\n");
            setbuf(stdin, NULL);
            scanf("%[A-Z a-z]s", servicos[j].nome);
            
            printf("Quantos insumos voce quer adicionar? (No maximo 10) \n");
            scanf("%d", &qtd);
            if (qtd > 10) {
                while(qtd > 10){
                    printf("Capacidade maxima de insumos excedida, inclua no maximo 10 insumos!\n");
                    scanf("%d", &qtd);
                }
            }
            
            printf("Quais os codigos dos insumos?\n");
            for(k = 0; k < qtd; k++){
                scanf("%d", &servicos[j].codigo_insumos[k]);
                for(z = 0; z < k; z++){
                    while (servicos[j].codigo_insumos[z] == servicos[j].codigo_insumos[k]){
                        printf("Codigo ja adicionado, utilize outro valor.\n");
                        scanf("%d", &servicos[j].codigo_insumos[k]);
                    }
                }
            }
            
            
            printf("Qual a quantidade de cada insumo?\n");
            for(k = 0; k < qtd; k++){
                scanf("%d", &servicos[j].qtd_insumos[k]);
            }
            
            for(z = qtd; z < 10; z++){
                servicos[j].codigo_insumos[z] = 0;
                servicos[j].qtd_insumos[z] = 0;
            }
            
            
            printf("Servico inserido com sucesso!\n");
            break;
        }
    }
}

void excluir_servico(servico *servicos, int m){
    
    char nome[20];
    int loop = 0, i, k;
    
    printf("Qual o nome do servico que voce deseja excluir?\n");
    setbuf(stdin, NULL);
    scanf("%[A-Z a-z]s", nome);
    
    for (i = 0; i < m; i++) {
        if (strcmp(servicos[i].nome, nome) == 0) {
            strcpy(servicos[i].nome, "");
            for (k = 0; k < 10; k++) {
                servicos[i].codigo_insumos[k] = 0;
                servicos[i].qtd_insumos[k] = 0;
                
            }
            loop = 1;
        }
    }
    
    if (loop == 0){
        printf("Nome de servico nao encontrado!\n");
    }
    else {
        printf("Servico excluido com sucesso!\n");
    }
    
}

void imprimir_insumos(insumo *insumos, int n){
    
    int i, j;
    char tipo;
    char nome_aux[20];
    int codigo_aux;
    char tipo_aux;
    float custo_aux;
    
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++) {
            if((strcmp(insumos[i].nome, insumos[j].nome) < 0) && (insumos[i].codigo != 0) && (insumos[j].codigo != 0)){
                strcpy(nome_aux, insumos[i].nome);
                strcpy(insumos[i].nome, insumos[j].nome);
                strcpy(insumos[j].nome, nome_aux);
                
                codigo_aux = insumos[i].codigo;
                insumos[i].codigo = insumos[j].codigo;
                insumos[j].codigo = codigo_aux;
                
                tipo_aux = insumos[i].tipo;
                insumos[i].tipo = insumos[j].tipo;
                insumos[j].tipo = tipo_aux;
                
                custo_aux = insumos[i].custo;
                insumos[i].custo = insumos[j].custo;
                insumos[j].custo = custo_aux;
            }
        }
    }
    
    
    printf("Qual o tipo de insumo deseja imprimir? (H para Recursos Humanos ou M para Materiais)\n");
    scanf(" %c", &tipo);
    while (( tipo != 'H') && (tipo != 'M') && (tipo != 'h') && (tipo != 'm')) {
        printf("Opcao inexistente, digite H para Recursos Humanos ou M para Materiais\n");
        scanf(" %c", &tipo);
    }
    
    printf("%c", tipo);
    
    if ((tipo == 'H') || (tipo == 'h')){
        for(i = 0; i < n; i++){
            if ((( insumos[i].tipo == 'H') || ( insumos[i].tipo == 'h')) && (insumos[i].codigo != 0)){
                printf("\nNome do Insumo = %s \n", insumos[i].nome);
                printf("Codigo do Insumo = %d \n", insumos[i].codigo);
                printf("Tipo do Insumo = Recursos Humanos \n");
                printf("Custo do insumo = %.2f \n", insumos[i].custo);
                printf("----------------------- \n");
                
            }
        }
    }
    else if ((tipo == 'M') || (tipo == 'm')){
        for(i = 0; i < n; i++){
            if ((( insumos[i].tipo == 'M') || ( insumos[i].tipo == 'm')) && (insumos[i].codigo != 0)){
                printf("\n Nome do Insumo = %s \n", insumos[i].nome);
                printf("Codigo do Insumo = %d \n", insumos[i].codigo);
                printf("Tipo do Insumo = Materiais \n");
                printf("Custo do insumo = %.2f \n", insumos[i].custo);
                printf("----------------------- \n");
            }
        }
    }
}

void imprimir_servicos(servico *servicos, int m){
    int i, k, j;
    char nome_aux[20];
    int codigo_insumos_aux[10];
    int qtd_insumos_aux[10];
    
    
    for (i = 0; i < m; i++){
        for (j = 0; j < m; j++) {
            if((strcmp(servicos[i].nome, servicos[j].nome) < 0) && (servicos[i].codigo_insumos[0] != 0) && (servicos[j].codigo_insumos[0] != 0)){
                strcpy(nome_aux, servicos[i].nome);
                strcpy(servicos[i].nome, servicos[j].nome);
                strcpy(servicos[j].nome, nome_aux);
                
                for (k = 0; k < 10; k++) {
                    codigo_insumos_aux[k] = servicos[i].codigo_insumos[k];
                    servicos[i].codigo_insumos[k] = servicos[j].codigo_insumos[k];
                    servicos[j].codigo_insumos[k] = codigo_insumos_aux[k];
                }
                for (k = 0; k < 10; k++) {
                    qtd_insumos_aux[k] = servicos[i].qtd_insumos[k];
                    servicos[i].qtd_insumos[k] = servicos[j].qtd_insumos[k];
                    servicos[j].qtd_insumos[k] = qtd_insumos_aux[k];
                }
                
            }
        }
    }
    
    for (i = 0; i < m; i++) {
        
        if (strcmp(servicos[i].nome, "" ) != 0) {
            
            printf("Nome do Servico = %s \n" ,servicos[i].nome);
            printf("Codigos dos Insumos = ");
            for (k = 0; k < 10; k++){
                printf("%d ", servicos[i].codigo_insumos[k]);
            }
            printf("\n");
            printf("Quantidade dos Insumos = ");
            for (k = 0; k < 10; k ++) {
                printf("%d ", servicos[i].qtd_insumos[k]);
            }
            printf("\n");
            printf("---------------\n");
        }
    }
}

void consultar_insumo(insumo *insumos, int n){
    
    int cod, loop = 0, i;
    
    printf("Qual o codigo do insumo que deseja consultar?\n");
    scanf("%d", &cod);
    
    for (i = 0; i < n ; i++) {
        if (cod == insumos[i].codigo) {
            printf("Nome do Insumo = %s \n", insumos[i].nome);
            printf("Codigo do Insumo = %d \n", insumos[i].codigo);
            if (insumos[i].tipo == 'H' || insumos[i].tipo == 'h') {
                printf("Tipo do Insumo = Recursos Humanos\n");
            }
            else if (insumos[i].tipo == 'M' || insumos[i].tipo == 'm'){
                printf("Tipo do Insumo = Materiais\n");
            }
            printf("Custo do insumo = %.2f \n", insumos[i].custo);
            loop = 1;
        }
    }
    
    if (loop == 0) {
        printf("Codigo do Insumo nao encontrado, tente novamente!\n");
    }
}

void consultar_servico(servico *servicos, int m){
    
    char nome[20];
    int loop = 0, i, k;
    
    printf("Qual o nome do servico que voce deseja consultar?\n");
    setbuf(stdin, NULL);
    scanf("%[A-Z a-z]s", nome);
    
    for (i = 0; i < m; i++) {
        if (strcmp(servicos[i].nome, nome) == 0) {
            printf("Nome do Servico = %s \n" ,servicos[i].nome);
            printf("Codigos dos Insumos = ");
            for (k = 0; k < 10; k++){
                printf("%d ", servicos[i].codigo_insumos[k]);
            }
            printf("\n");
            printf("Quantidade dos Insumos = ");
            for (k = 0; k < 10; k ++) {
                printf("%d ", servicos[i].qtd_insumos[k]);
            }
            printf("\n");
            loop = 1;
        }
        
    }
    
    if (loop == 0) {
        printf("Servico nao encontrado, tente novamente!\n");
    }
}

void alterar_insumo(insumo *insumos, int n){
    
    char conf;
    char nome[20];
    int codigo, cod, loop = 0, k;
    char tipo;
    float custo;
    
    printf("Qual o codigo do insumo que voce deseja alterar?\n");
    scanf("%d", &cod);
    
    for(k = 0; k < n; k++){
        if(insumos[k].codigo == cod){
            
            loop = 1;
            printf("Qual o novo nome do insumo?\n");
            setbuf(stdin, NULL);
            scanf("%[A-Z a-z]s", nome);
            
            
            printf("Qual o novo codigo do insumo?\n");
            scanf("%d", &codigo);
            
            
            printf("Qual o novo tipo do insumo? (H para Recursos Humanos ou M para Materiais)\n");
            scanf(" %c", &tipo);
            while (( tipo != 'H') && (tipo != 'M') && ( tipo != 'h') && (tipo != 'm')) {
                printf("Opcao inexistente, digite H para Recursos Humanos ou M para Materiais\n");
                scanf(" %c", &tipo);
            }
            
            printf("Qual o novo custo unitario do insumo?\n");
            scanf("%f", &custo);
            
            
            printf("Voce tem certeza que deseja alterar o insumo abaixo? (S para SIM e N para NAO) \n\n");
            printf("----------------------\n");
            printf("Nome do Insumo =  %s => %s \n", insumos[k].nome, nome);
            printf("Codigo do Insumo =  %d => %d \n", insumos[k].codigo, codigo);
            printf("Tipo do Insumo =  %c => %c \n", insumos[k].tipo, tipo);
            printf("Custo do insumo =  %.2f => %.2f \n", insumos[k].custo, custo);
            printf("----------------------\n");
            scanf(" %c", &conf);
            
            while (conf != 'S' && conf != 's' && conf != 'n' && conf != 'N') {
                printf("Opcao inexistente, Digite S (sim) ou N (nao)\n");
                scanf(" %c", &conf);
            }
            
            if (conf == 'S'  || conf == 's') {
                strcpy(insumos[k].nome, nome);
                insumos[k].codigo = codigo;
                insumos[k].tipo = tipo;
                insumos[k].custo = custo;
                
                printf("Insumo alterado com sucesso!\n");
                break;
            }
            else if (conf == 'N' || conf == 'n'){
                printf("Insumo nao alterado!\n");
                break;
            }
        }
    }
    
    if (loop == 0) {
        printf("Codigo nao encontrado, tente novamente!\n");
    }
}


void alterar_servico(servico *servicos, int m){
    
    int qtd, loop = 0, j, k, x, z;
    char nome[20];
    char nome_novo[20];
    char conf;
    int codigo_insumos[10];
    int qtd_insumos[10];
    
    printf("Qual o nome do servico que voce deseja alterar?\n");
    setbuf(stdin, NULL);
    scanf("%[A-Z a-z]s", nome);
    
    for(j = 0; j < m; j++){
        if(strcmp(servicos[j].nome, nome) == 0){
            
            loop = 1;
            printf("Qual o novo nome do servico?\n");
            setbuf(stdin, NULL);
            scanf("%[A-Z a-z]s", nome_novo);
            
            printf("Qual a nova quantidade de insumos que o servico tera?\n");
            scanf("%d", &qtd);
            
            printf("Quais os novo codigos dos insumos?\n");
            for(k = 0; k < qtd; k++){
                scanf("%d", &codigo_insumos[k]);
                for(z = 0; z < k; z++){
                    while (codigo_insumos[z] == codigo_insumos[k]){
                        printf("Codigo ja adicionado, utilize outro valor.\n");
                        scanf("%d", &codigo_insumos[k]);
                    }
                }
            }
            
            for (x = qtd; x < 10; x++) {
                codigo_insumos[x] = 0;
            }
            
            printf("Qual a nova quantidade de cada insumo?\n");
            for(k = 0; k < qtd; k++){
                scanf("%d", &qtd_insumos[k]);
            }
            
            for (x = qtd; x < 10; x++) {
                qtd_insumos[x] = 0;
            }
            
            printf("Voce tem certeza que deseja alterar o servico abaixo? (S para SIM e N para NAO) \n\n");
            printf("----------------------\n");
            printf("Nome do Servico =  %s => %s \n", servicos[j].nome, nome_novo);
            printf("Codigos dos Insumos = ");
            for (z = 0; z < 10; z++){
                printf("%d ", servicos[j].codigo_insumos[z]);
            }
            printf(" => ");
            for(z = 0; z < 10; z++){
                printf("%d ", codigo_insumos[z]);
            }
            printf("\n");
            printf("Quantidade dos Insumos = ");
            for (z = 0; z < 10; z++){
                printf("%d ", servicos[j].qtd_insumos[z]);
            }
            printf(" => ");
            for(z = 0; z < 10; z++){
                printf("%d ", qtd_insumos[z]);
            }
            printf("\n");
            printf("----------------------\n");
            scanf(" %c", &conf);
            
            while (conf != 'S' && conf != 's' && conf != 'n' && conf != 'N') {
                printf("Opcao inexistente, Digite S (sim) ou N (nao)\n");
                scanf(" %c", &conf);
            }
            
            if (conf == 'S'  || conf == 's') {
                strcpy(servicos[j].nome, nome_novo);
                for(z = 0; z < 10; z++){
                    servicos[j].codigo_insumos[z] = codigo_insumos[z];
                    servicos[j].qtd_insumos[z] = qtd_insumos[z];
                }
                
                printf("Servico alterado com sucesso!\n");
                break;
            }
            else if (conf == 'N' || conf == 'n'){
                printf("Servico nao alterado!\n");
                break;
            }
        }
    }
    
    if (loop == 0) {
        printf("Nome do servico nao encontrado, tente novamente!\n");
    }
}

void orcar_servico(insumo *insumos, servico *servicos, int n, int m){
    
    float valor_total = 0;
    float vetor_de_valores[10] = {0,0,0,0,0,0,0,0,0,0};
    int loop = 0;
    int pos = 0;
    char nome[20];
    int j, i, z, k;
    
    printf("Qual o nome do servico que voce deseja consultar?\n");
    setbuf(stdin, NULL);
    scanf("%[A-Z a-z]s", nome);
    printf("Orcando servico...\n");
    
    for (j = 0; j < m; j++) {
        if (strcmp(servicos[j].nome, nome) == 0) {
            loop = 1;
            for (z = 0; z < 10; z++) {
                for (i = 0; i < n; i++){
                    if ((servicos[j].codigo_insumos[z] != 0) && (servicos[j].codigo_insumos[z] == insumos[i].codigo)) {
                        vetor_de_valores[pos] = servicos[j].qtd_insumos[z] * insumos[i].custo;
                        pos++;
                    }
                }
            }
        }
    }
    
    for (k = 0; k < 10; k++) {
        if (vetor_de_valores[k] != 0){
        valor_total = valor_total + vetor_de_valores[k];
        }
    }
    if (loop == 1){
        printf("Valor total da obra =  %.2f reais \n", valor_total);
    }
    else if (loop == 0){
        printf("Servico nao encontrado, tente novamente!\n");
    }
    
}

void orcar_obra(insumo *insumos, servico *servicos, int n, int m){


    float vetor_de_valores = 0;
    float custo_servico[m][10];
    int i, j, k, pos = 0;
    
    for (i = 0; i < m; i++) {
        for (k = 0 ; k < 10; k++) {
            custo_servico[i][k] = 0; 
        }
    }
    
    for (j = 0; j < m; j++) {
        for(k = 0; k < 10; k++) {
            for (i = 0; i < n; i++) {
                if ((servicos[j].codigo_insumos[0] != 0) && (servicos[j].codigo_insumos[k] == insumos[i].codigo)){
                    custo_servico[j][pos] = servicos[j].qtd_insumos[k] * insumos[i].custo;
                    pos++;
                }
            }
        }
    }
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < 10; j++) {
            vetor_de_valores = vetor_de_valores + custo_servico[i][j];
        }
    }
    
    printf("%.2f", vetor_de_valores);
    
}


int main(){
    
    int n = 0, m = 0, op = 0;
    
    printf("\nQual o maximo de insumo voce ira adicionar?\n");
    scanf("%d", &n);
    
    printf("\nQual o maximo de servicos voce ira adicionar?\n");
    scanf("%d", &m);
    
    insumo *insumos = (insumo*) calloc(n, sizeof(insumo));
    servico *servicos = (servico*) calloc(m, sizeof(servico));
    
    
    while (op != 13) {
        
        
        
        printf("\t\n------ BEM-VINDO AO SISTEMA DE ORGANIZACAO DE INSUMOS E SERVICOS ------\n\n");
        printf("Qual opcao voce deseja?\n");
        printf("1) Inserir insumo\n");
        printf("2) Inserir servico\n");
        printf("3) Excluir insumo\n");
        printf("4) Excluir servico\n");
        printf("5) Imprimir insumos\n");
        printf("6) Imprimir servicos\n");
        printf("7) Consultar insumo\n");
        printf("8) Consultar servico\n");
        printf("9) Alterar insumo\n");
        printf("10) Alterar servico\n");
        printf("11) Orcar servico\n");
        printf("12) Orcar obra\n");
        //printf("13) Ler dados de Arquivo\n");
        //printf("14) Salvar dados em Arquivo\n");
        printf("13) Sair do programa\n");
        
        scanf("%d", &op);
        
        switch (op) {
                
            case 1:
                inserir_insumo(insumos, n);
                break;
            case 2:
                inserir_servico(servicos, m);
                break;
            case 3:
                excluir_insumo(insumos, n);
                break;
            case 4:
                excluir_servico(servicos, m);
                break;
            case 5:
                imprimir_insumos(insumos, n);
                break;
            case 6:
                imprimir_servicos(servicos, m);
                break;
            case 7:
                consultar_insumo(insumos, n);
                break;
            case 8:
                consultar_servico(servicos, m);
                break;
            case 9:
                alterar_insumo(insumos, n);
                break;
            case 10:
                alterar_servico(servicos, m);
                break;
            case 11:
                orcar_servico(insumos, servicos, n, m);
                break;
            case 12:
                orcar_obra(insumos, servicos, n, m);
                break;
            //case 13:
                break;
            //case 14:
                break;
            case 13:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao inexistente!\n");
                break;
                
        }
        
    }
    
    return 0;
    
}
