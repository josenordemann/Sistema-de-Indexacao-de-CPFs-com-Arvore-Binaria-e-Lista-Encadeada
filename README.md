# Sistema de Indexação de CPFs - Árvore Binária & Lista Encadeada 🌳📄

![Language](https://img.shields.io/badge/language-C-blue)
![Course](https://img.shields.io/badge/course-Estrutura%20de%20Dados-green)
![Institution](https://img.shields.io/badge/USP-ICMC%2FEESC-orange)

## 📖 Sobre o Projeto

Este projeto consiste na implementação de uma solução híbrida de **Tipos Abstratos de Dados (TAD)** em linguagem C, integrando uma **Árvore Binária de Busca (BST)** com uma **Lista Dinâmica Duplamente Encadeada**.

O software foi desenvolvido no contexto da disciplina **SSC0603 - Estrutura de Dados** da Universidade de São Paulo (USP), abordando a manipulação avançada de ponteiros para indexação eficiente de registros.

## 🎯 Definição do Problema e Lógica

O programa processa um arquivo CSV (`basedados.csv`) contendo registros de pessoas (CPF, Código de Verificação, Data de Nascimento e Nome). O objetivo é combinar a eficiência de busca da árvore com a capacidade de armazenamento sequencial da lista.

A lógica de integração funciona da seguinte maneira:

1.  **Armazenamento Completo (Lista):** Todos os dados lidos do CSV são inseridos em uma **Lista Duplamente Encadeada**. Isso permite percorrer os dados sequencialmente e preserva a ordem de inserção ou manipulação.
2.  **Indexação (Árvore):** O CPF é inserido na **Árvore Binária** para permitir buscas rápidas (O(log n)).
3.  **Ponteiro Cruzado:** O diferencial deste projeto é que cada nó da Árvore possui um ponteiro direto (`*no_cor`) para o nó correspondente na Lista. Assim, ao encontrar um CPF na árvore, o acesso aos dados completos (Nome, Data, CV) é imediato, sem necessidade de percorrer a lista linearmente.

## 🛠️ Tecnologias e Conceitos

* **Linguagem C** (Padrão ANSI).
* **Integração de Estruturas:** Ponteiros conectando nós de árvores a nós de listas.
* **Árvore Binária de Busca (BST):** Para ordenação e busca eficiente por chave (CPF).
* **Lista Duplamente Encadeada:** Para armazenamento robusto dos registros completos.
* **Manipulação de Arquivos:** Leitura de CSV e geração de relatórios `.txt`.
* **Recursividade:** Utilizada nas operações de inserção, remoção e caminhamento na árvore.

## 📂 Estrutura do Repositório

* `main.c`: Orquestra o menu, leitura do arquivo e chamadas das funções.
* `ArvoreBinaria.c` / `.h`: Implementação da Árvore e funções de caminhamento (Em Ordem).
* `LDED.c` / `.h`: Implementação da Lista (inserção, remoção e consulta).
* `basedados.csv`: Arquivo de entrada com os dados brutos.

## ⚙️ Funcionalidades do Menu

O programa apresenta no console métricas da árvore (total de nós, altura, e os dados do primeiro e último elementos na ordem). 

Através do menu de entrada, o programa opera em dois modos:
1.  **Modo 1:** Executa a leitura, constrói as estruturas em memória e gera silenciosamente os arquivos de saída.
2.  **Modo 2:** Executa todo o processo do Modo 1 e, ao final, utiliza o comando `system("cat...")` para exibir automaticamente no terminal o conteúdo dos três arquivos gerados.

**Arquivos Gerados:**
* `dados1.txt`: Conteúdo completo da LDE (inserções no início).
* `dados2.txt`: CPFs da árvore impressos no percurso **Em Ordem**.

## 🚀 Como Compilar e Executar

Para compilar o projeto, utilize um compilador GCC.

### 1. Compilação
Abra o terminal na raiz do projeto e execute:

```bash
gcc main.c ArvoreBinaria.c LDED.c -o programa
```

### 2. Execução

```bash
./programa
```
