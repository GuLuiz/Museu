# Sistema de gerenciamento de um museu multitemático

Este projeto foi criado como parte de um trabalho acadêmico na faculdade, com o objetivo de atender aos requisitos do curso Análise e desenvolvimento de sistema da UNIP(Universidade Paulista). Ele é desenvolvido para fins educativos, proporcionando uma oportunidade para aplicar e aprimorar os conhecimentos adquiridos durante o semestre.


## Descrição do Projeto

O Museu Multitemático é um sistema desenvolvido para atender às necessidades de gestão de um museu, proporcionando uma experiência digital para visitantes e facilitando as operações administrativas. Algumas das principais funcionalidades incluem:

- **Bilheteria Digital:** Um sistema de bilheteria online que permite aos visitantes comprar ingressos de forma rápida e conveniente.

- **Obras e Questionários:** O sistema apresenta quatro obras exclusivas, cada uma acompanhada por um questionário de 4 perguntas com escalas de 0 a 10. Os visitantes têm a oportunidade de avaliar e fornecer feedback sobre as obras, contribuindo para a análise do museu.

- **Área Administrativa:** Os administradores têm acesso a uma interface dedicada, onde podem visualizar os bilhetes cadastrados e gerar relatórios automatizados com base nas respostas dos questionários. Isso fornece uma visão abrangente do feedback dos visitantes e auxilia na tomada de decisões para melhorias futuras.


## Como Usar

Ao iniciar o sistema, os usuários têm acesso a duas partes distintas: a seção do visitante e a do administrador.

### Parte do Administrador

1. Ao selecionar a opção de administrador, será exibida uma tela de login.
2. Utilize as seguintes credenciais para autenticação:
    - **Login:** Admin
    - **Senha:** admin
3. Após o login bem-sucedido, o administrador terá acesso às seguintes funcionalidades:
    - Visualização de bilhetes cadastrados.
    - Geração de relatórios automáticos com base nas respostas dos questionários.

### Parte do Visitante

1. Ao selecionar a opção de visitante, os usuários entrarão na área de cadastro da bilheteria.
2. Complete o cadastro da bilheteria, fornecendo as informações necessárias.
3. Após o cadastro, será gerado um código ID único associado ao bilhete.
4. Utilize esse código ID para acessar as obras e os questionários disponíveis.



```bash
# Para executar o programa no VisualStudio code compile esse codigo no seu terminal dentro da pasta Museu

gcc -o main main.c quest.c MenuAdm.c obrasMenu.c obrasAdm.c menuVisitante.c bilheteria.c login.c loginAdmin.c Relatorio.c backup.c

