app.out : main_revise.o cJSON.o
	gcc -o app.out main_revise.c cJSON.c

main.o : main_revise.c
	gcc -c -o main_revise.o main_revise.c

linkedList.o : cJSON.h cJSON.c
	gcc -c -o cJSON.o cJson.c
