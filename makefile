bin/proFile: a3Main.o helperA3.o recruitEmployee.o printAll.o printOne.o lookOnId.o lookOnFullName.o countEmployees.o sortEmployeesId.o fireOne.o fireAll.o
	gcc -std=c99 -Wall a3Main.o helperA3.o recruitEmployee.o printAll.o printOne.o lookOnId.o lookOnFullName.o countEmployees.o sortEmployeesId.o fireOne.o fireAll.o -o bin/proFile -lm
a3Main.o: src/a3Main.c include/headerA3.h
	gcc -std=c99 -Wall -c -g src/a3Main.c
helperA3.o: src/helperA3.c include/headerA3.h
	gcc -std=c99 -Wall -c -g src/helperA3.c
recruitEmployee.o: src/recruitEmployee.c include/headerA3.h
	gcc -std=c99 -Wall -c -g src/recruitEmployee.c
printAll.o: src/printAll.c include/headerA3.h
	gcc -std=c99 -Wall -c -g src/printAll.c
printOne.o: src/printOne.c include/headerA3.h
	gcc -std=c99 -Wall -c -g src/printOne.c
lookOnId.o: src/lookOnId.c include/headerA3.h
	gcc -std=c99 -Wall -c -g src/lookOnId.c
lookOnFullName.o: src/lookOnFullName.c include/headerA3.h
	gcc -std=c99 -Wall -c -g src/lookOnFullName.c
countEmployees.o: src/countEmployees.c include/headerA3.h
	gcc -std=c99 -Wall -c -g src/countEmployees.c
sortEmployeesId.o: src/sortEmployeesId.c include/headerA3.h
	gcc -std=c99 -Wall -c -g src/sortEmployeesId.c
fireOne.o: src/fireOne.c include/headerA3.h
	gcc -std=c99 -Wall -c -g src/fireOne.c
fireAll.o: src/fireAll.c include/headerA3.h
	gcc -std=c99 -Wall -c -g src/fireAll.c
clean:
	rm *.o bin/proFile
