main: main.o DirectoryOperations.o extrautility.o FileExplorerOptions.o FileExploration.o NavigateContent.o RenameFile.o DeleteFile.o FileOperations.o ApplicationViewer.o
	g++ main.o DirectoryOperations.o extrautility.o FileExplorerOptions.o FileExploration.o NavigateContent.o RenameFile.o DeleteFile.o FileOperations.o ApplicationViewer.o -o main

main.o: main.cpp
	g++ -c main.cpp

DirectoryOperations.o: DirectoryOperations.cpp
	g++ -c  DirectoryOperations.cpp

extrautility.o: extrautility.cpp
	g++ -c extrautility.cpp

FileExplorerOptions.o: FileExplorerOptions.cpp
	g++ -c FileExplorerOptions.cpp

FileExploration.o: FileExploration.cpp
	g++ -c FileExploration.cpp

NavigateContent.o: NavigateContent.cpp
	g++ -c NavigateContent.cpp

RenameFile.o: RenameFile.cpp
	g++ -c RenameFile.cpp

DeleteFile.o: DeleteFile.cpp
	g++ -c DeleteFile.cpp

FileOperations.o: FileOperations.cpp
	g++ -c FileOperations.cpp

ApplicationViewer.o: ApplicationViewer.cpp
	g++ -c ApplicationViewer.cpp