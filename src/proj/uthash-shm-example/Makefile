build:
	gcc prod.c shared_table.c -std=gnu99 -lrt -pthread -o prod
	gcc cons.c shared_table.c -std=gnu99 -lrt -pthread -o cons

run:
	./prod
	./cons
	rm /dev/shm/testing
