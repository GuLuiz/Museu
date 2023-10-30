 #include <stdlib.h>
 #include <stdio.h>
 #include <String.h>

 int LoginAdmin() {
    char loginAdmin[20];
    char senhaAdmin[20];
    char login[20];
    char senha[20];
    char voltar;
    int deciMenuAdm;
    int sair = 0;
    FILE *LoginAdmin;
    FILE *SenhaAdmin;
    LoginAdmin = fopen("D:\\Login\\Login.txt", "r");
    SenhaAdmin = fopen("D:\\Login\\Senha.txt", "r");

    if (LoginAdmin == NULL || SenhaAdmin == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    fgets(loginAdmin, sizeof(loginAdmin), LoginAdmin);
    fgets(senhaAdmin, sizeof(senhaAdmin), SenhaAdmin);

    while (sair == 0) {
        printf("\n***********************************************");
        printf("\nLOGIN ADMINISTRADOR");
        printf("\nLogin: ");
        scanf("%s", login);

        if (login[strlen(login) - 1] == '\n') {
            login[strlen(login) - 1] = '\0';
        }


        if (senha[strlen(senha) - 1] == '\n') {
            senha[strlen(senha) - 1] = '\0';
        }
        printf("\nSenha: ");
        scanf("%s", senha);
        printf("***********************************************\n");


        if (strcmp(login, loginAdmin) == 0 && strcmp(senha, senhaAdmin) == 0) {
            printf("Login realizado com sucesso\n");
            printf("***********************************************\n");
            printf("           MENU ADMINISTRADOR");
            printf("\n***********************************************\n");
            printf("1 - Visualizar obras");
            printf("\n2 - Visualizar relatórios");
            printf("\n3 - Gerar arquivos\n");
            scanf("%d", &deciMenuAdm);
            sair++;
        } else {
            printf("Credenciais incorretas\n");
            printf("Deseja tentar novamente? s/n\n");
            scanf("%s",&voltar);
            if(voltar == 'n'){
            sair ++;
            } 
        }
    }
    fclose(LoginAdmin);
    fclose(SenhaAdmin);
    return 0;
}