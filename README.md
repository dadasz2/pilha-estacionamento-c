Segue um README no mesmo estilo do exemplo que você enviou, adaptado para o seu projeto de estacionamento utilizando Pilha.

# Sistema de Estacionamento

Sistema de gerenciamento de um estacionamento de corredor único desenvolvido em C, utilizando uma pilha encadeada e persistência em arquivo. O programa permite estacionar veículos, listar os veículos presentes, retirar o veículo da saída e salvar os dados automaticamente.

**Disciplina:** DSA (Estrutura de Dados e Algoritmos)

**Autores:** Dácio ______ e __________

**Objetivo:** Praticar implementação de pilhas encadeadas, alocação dinâmica de memória, manipulação de arquivos e estruturas de dados em linguagem C.

---

# Funcionalidades

✅ Estacionar novos veículos

✅ Listar todos os veículos estacionados

✅ Retirar o veículo da saída

✅ Visualizar o veículo que está no topo da pilha

✅ Salvar dados em arquivo

✅ Carregar dados automaticamente ao iniciar

✅ Salvar automaticamente ao encerrar o programa

---

# Funcionamento da Pilha

O estacionamento funciona como um corredor único.

O último veículo que entra é o primeiro que consegue sair.

Exemplo:

Entrada dos veículos:

1. Corolla
2. HB20
3. Gol

Situação da pilha:

```text
Topo

Gol
HB20
Corolla

Base
```

Ao retirar um veículo, o Gol será removido primeiro.

---

# Estrutura de Dados

O sistema utiliza uma Pilha Encadeada Dinâmica, onde cada veículo possui:

```c
typedef struct Veiculo{

    char placa[15];
    char modelo[50];
    char proprietario[50];

    struct Veiculo *prox;

} Veiculo;
```

O ponteiro principal do sistema é:

```c
Veiculo *topo = NULL;
```

Ele sempre aponta para o último veículo estacionado.

---

# Arquivos Gerados

| Arquivo            | Descrição                        |
| ------------------ | -------------------------------- |
| estacionamento.txt | Veículos atualmente estacionados |

Formato do arquivo:

```text
placa;modelo;proprietario
```

Exemplo:

```text
ABC1234;Corolla;Carlos Silva
DEF5678;HB20;Ana Souza
JKL4321;Gol;Pedro Santos
```

---

# Menu do Sistema

```text
=================================
     SISTEMA DE ESTACIONAMENTO
=================================
1 - Estacionar veiculo
2 - Retirar veiculo
3 - Listar veiculos
4 - Mostrar veiculo da saida
5 - Salvar dados
6 - Sair
```

---

# Como Compilar

### GCC (Linux / MinGW)

```bash
gcc main.c -o estacionamento
```

### Dev-C++

* Abra o arquivo `main.c`
* Clique em **Executar → Compilar e Executar**

---

# Como Executar

### Windows

```text
estacionamento.exe
```

### Linux / Mac

```bash
./estacionamento
```

---

# Exemplo de Uso

1. Execute o programa.
2. Escolha a opção **1** para estacionar um veículo.
3. Informe a placa, modelo e proprietário.
4. Escolha a opção **3** para visualizar os veículos.
5. Escolha a opção **2** para retirar o veículo da saída.
6. Utilize a opção **5** para salvar manualmente.
7. Escolha a opção **6** para sair do sistema.

---

# Lógica do Sistema

## Pilha (Stack)

O sistema segue o conceito LIFO (Last In, First Out):

* Último veículo que entra.
* Primeiro veículo que sai.

Esse comportamento representa exatamente um estacionamento de corredor único.

---

## Persistência

* Os veículos são armazenados em `estacionamento.txt`.
* Os dados são carregados automaticamente ao iniciar o sistema.
* O programa salva automaticamente ao ser encerrado.

---

# Funções Principais

| Função            | Descrição                   |
| ----------------- | --------------------------- |
| push()            | Estaciona um novo veículo   |
| pop()             | Retira o veículo do topo    |
| listar()          | Exibe todos os veículos     |
| mostrarTopo()     | Mostra o veículo da saída   |
| salvarArquivo()   | Salva os dados no arquivo   |
| carregarArquivo() | Carrega os dados salvos     |
| liberarMemoria()  | Libera toda memória alocada |

---

# Tecnologias Utilizadas

* Linguagem C (C11)
* Alocação dinâmica (`malloc` e `free`)
* Manipulação de arquivos (`fopen`, `fprintf`, `fgets`, `strtok`)
* Estrutura de Dados: Pilha Encadeada
* Biblioteca padrão da linguagem C

---

# Limitações Conhecidas

* O estacionamento possui apenas uma entrada e uma saída.
* Não é possível retirar um veículo que não esteja no topo da pilha.
* Não há limite máximo de vagas implementado.
* O sistema não realiza busca por placa ou proprietário.
* Não existe funcionalidade para editar informações de um veículo já estacionado.

---

# Melhorias Futuras

* Buscar veículo pela placa.
* Definir limite máximo de vagas.
* Excluir um veículo específico.
* Implementar interface gráfica.
* Separar o projeto em arquivos `.h` e `.c`.
* Adicionar horário de entrada dos veículos.
* Calcular valor de permanência no estacionamento.

---

# Autor

Desenvolvido por Dácio ______ e __________.

---

# Licença

Projeto desenvolvido para fins acadêmicos na disciplina de DSA (Estrutura de Dados e Algoritmos).
