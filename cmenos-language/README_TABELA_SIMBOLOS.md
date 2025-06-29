# Tabela de Símbolos para Compilador C-

Este projeto implementa uma tabela de símbolos simples para o compilador da linguagem C-.

## Funcionalidades

A tabela de símbolos suporta:

- **Variáveis**: Armazena nome, tipo de dados, linha, coluna e escopo
- **Funções**: Armazena nome, tipo de retorno, parâmetros e escopo
- **Parâmetros**: Armazena informações dos parâmetros de funções
- **Estruturas**: Armazena definições de estruturas
- **Arrays**: Suporta arrays unidimensionais e multidimensionais
- **Escopos**: Gerencia diferentes níveis de escopo (global, função, bloco)

## Estrutura dos Arquivos

- `symbol_table.h`: Definições das estruturas e funções
- `symbol_table.c`: Implementação da tabela de símbolos
- `language01.y`: Parser Bison integrado com a tabela de símbolos
- `language01.l`: Scanner Flex modificado para retornar strings

## Como Compilar

```bash
# Dar permissão de execução ao script
chmod +x CompileRun.sh

# Executar a compilação
./CompileRun.sh
```

## Como Usar

```bash
# Compilar um arquivo de teste
./compilador teste_tabela_simbolos.txt
```

## Funcionalidades da Tabela de Símbolos

### 1. Inserção de Símbolos
- `insertSymbol()`: Insere um novo símbolo na tabela
- Verifica duplicatas no mesmo escopo
- Armazena informações como tipo, linha, coluna e escopo

### 2. Busca de Símbolos
- `lookupSymbol()`: Busca símbolo em um escopo específico
- `lookupSymbolGlobal()`: Busca símbolo em qualquer escopo

### 3. Gerenciamento de Escopos
- `enterScope()`: Entra em um novo escopo
- `exitScope()`: Sai do escopo atual e remove símbolos locais

### 4. Verificações Semânticas
- Verifica se variáveis estão declaradas antes do uso
- Verifica se funções estão declaradas antes da chamada
- Verifica se arrays estão sendo usados corretamente
- Detecta redeclarações no mesmo escopo

## Exemplo de Saída

```
=== ANÁLISE SINTÁTICA E SEMÂNTICA CONCLUÍDA ===

=== TABELA DE SÍMBOLOS ===
Escopo atual: 0
Total de símbolos: 8

Nome            Tipo       Tipo Dados  Estrutura       Linha    Coluna   Escopo  
----------------------------------------------------------------
funcao3         Funcao     float       -               25       1        0       
funcao2         Funcao     void        -               20       1        0       
funcao1         Funcao     int         -               12       1        0       
Pessoa          Estrutura  struct      -               8        1        0       
array2          Variavel   array       -               6        1        0       
array1          Variavel   array       -               5        1        0       
variavel3       Variavel   char        -               4        1        0       
variavel2       Variavel   float       -               3        1        0       
variavel1       Variavel   int         -               2        1        0       
================================================================

==========================================
Análise sintática concluída com sucesso!
==========================================
```

## Tipos de Dados Suportados

- `int`: Números inteiros
- `float`: Números de ponto flutuante
- `char`: Caracteres
- `void`: Tipo vazio (para funções)
- `struct`: Estruturas definidas pelo usuário
- `array`: Arrays (com dimensões)

## Tipos de Símbolos

- `SYMBOL_VAR`: Variáveis
- `SYMBOL_FUNC`: Funções
- `SYMBOL_STRUCT`: Estruturas
- `SYMBOL_PARAM`: Parâmetros de funções

## Verificações de Erro

A tabela de símbolos detecta os seguintes erros:

1. **Variável não declarada**: Quando uma variável é usada sem ser declarada
2. **Função não declarada**: Quando uma função é chamada sem ser declarada
3. **Redeclaração**: Quando um símbolo é declarado duas vezes no mesmo escopo
4. **Uso incorreto de array**: Quando um array é usado incorretamente

## Limitações Atuais

- Suporte limitado a arrays multidimensionais
- Não verifica tipos de retorno de funções
- Não verifica compatibilidade de tipos em atribuições
- Não suporta ponteiros

## Próximos Passos

Para expandir a funcionalidade, considere:

1. Adicionar verificação de tipos
2. Implementar suporte completo a arrays multidimensionais
3. Adicionar suporte a ponteiros
4. Implementar verificação de tipos de retorno
5. Adicionar suporte a constantes 