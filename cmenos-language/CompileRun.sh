#!/bin/bash

# Compila a tabela de símbolos
gcc -c symbol_table.c -o symbol_table.o

# Gera o parser com Bison
bison -d language01.y

# Gera o scanner com Flex
flex language01.l

# Compila o scanner
gcc -c lex.yy.c -o lex.yy.o

# Compila o parser
gcc -c parser.tab.c -o parser.tab.o

# Linka tudo junto
gcc lex.yy.o parser.tab.o symbol_table.o -o compilador -lfl

# Limpa arquivos temporários
rm -f lex.yy.c parser.tab.c parser.tab.h *.o

echo "Compilação concluída! Use: ./compilador arquivo_entrada.txt" 
