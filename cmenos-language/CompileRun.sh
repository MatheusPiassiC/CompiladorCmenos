bison -d -o parser.tab.c language01.y
flex -o scanner.yy.c language01.l
gcc -o a symbol_table.c scanner.yy.c parser.tab.c #Linux: "-lfl" ao invés de "-ly -ll" 
