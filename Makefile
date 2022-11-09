CLANG = clang -std=c11 -Wall -Wextra -Werror -Wpedantic
SF = src/*.c 
OD = obj
EFN = libmx.a

all: install

install:
	@mkdir ${OD}
	@cd ${OD} && ${CLANG} -c ../${SF}
	@ar -rc ${EFN} ${OD}/*.o


uninstall: clean
	@rm -f ${EFN}

clean:
	@rm -rdf ${OD} 

reinstall: uninstall clean install

