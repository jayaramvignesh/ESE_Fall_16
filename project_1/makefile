include sources1.mk
#include headers1.mk

HOST = gcc
BBB = arm-linux-gnueabihf-gcc -DBBB
FF = arm-none-eabi-gcc -DFF

LINK = -Wl,-Map=project.map



.PHONY : preprocess memory.i data.i project_1.i main.i asm-file main.s data.s memory.s project_1.s compile-all compile-all-BBB compile-all-FF build build-BBB build-FF %.o dependencies dependencies-FF object_size build-lib project upload all everything 

CFLAGS = -Wall -g -O0 -std=c99 -c 
CFLAGS1 = -mcpu=cortex-m0plus -Wall -g -O0 -std=c99 -c 
CFLAGS2 = -mcpu=cortex-a8 -Wall -g -O0 -std=c99 -c 



all: compile-all project

everything: preprocess memory.i data.i project_1.i main.i asm-file compile-all compile-all-BBB build %.o dependencies object_size build-lib project

project : $(objects_o)
	$(HOST) -I headers $^ -o project 

preprocess : $(sources_c)
	$(HOST) -I headers -E $^ > file.i

memory.i : memory.c 
	$(HOST) $(CFLAGS) -I headers -E $^ > memory.i

data.i : data.c 
	$(HOST) $(CFLAGS) -I headers -E $^ > data.i

project_1.i : project_1.c 
	$(HOST) $(CFLAGS) -I headers -E $^ > project_1.i

main.i : main.c 
	$(HOST) $(CFLAGS) -I headers -E $^ > main.i

asm-file : main.c memory.c data.c project_1.c
	$(HOST) -I headers $^ -S

memory.s : memory.c 
	$(HOST) -I headers $^ -S -o memory.s

data.s : data.c 
	$(HOST) -I headers $^ -S -o data.s

project_1.s : project_1.c
	$(HOST) -I headers $^ -S -o project_1.s 

main.s : main.c 
	$(HOST) -I headers $^ -S -o main.s 

compile-all : $(sources_c) 
	$(HOST) -I headers $^ $(CFLAGS)

compile-all-BBB : $(sources_c) 
	$(BBB) -I headers $^ $(CFLAGS)

compile-all-FF : $(sources_c) 
	$(FF) -I headers $^ $(CFLAGS)

%.o : %.c 
	$(HOST) $(CFLAGS) -c $^ > %.o

build : $(sources_c)
	$(HOST) -I headers $^ $(CFLAGS) > project $(objects_o)
	$(HOST) -o project $(objects_o) $(LINK)
	objdump -g project

	

build-BBB : $(sources_c) 
	$(BBB) -I headers $^ $(CFLAGS2) > project $(objects_o)
	
	
	

build-FF : $(sources_c) 
	$(BBB) -I headers $^ $(CFLAGS1) > project-FF $(objects_o)
	size -d project-FF



dependencies : $(sources_c)
	$(HOST) -MM -I headers $^ -o project.dep
	$(BBB) -MM -I headers $^ -o project-BBB.dep
	
dependencies-FF : $(sources_c) 
	$(FF) -MM -I headers $^ -o project-FF.dep

object_size : $(objects_o)	
	size -d project
	
upload: 
	scp -r project/ root@192.168.7.2:/root/release

build-lib: memory.c data.c  
	ar cr libproject1.a $< 

direct_link : $(sources_c) 
	$(CC) -I headers $(CFLAGS) $^ 
	ld -o $(objects_o) -lc

clean:
	rm -rf *.o *.map *.i *.s *.dep *.a project


	


  
