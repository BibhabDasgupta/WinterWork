# Compiler settings
CC = gcc
CFLAGS = -shared -fpic -I/usr/lib/jvm/java-8-openjdk-amd64/include -I/usr/lib/jvm/java-8-openjdk-amd64/include/linux
JAVA = java
JAVAC = javac
JAVAH = javah

# Paths
JAVA_SRC = StringF.java
JAVA_CLASS = StringF.class
JNI_HEADER = StringF.h
C_SRC = StringF.c
SO_FILE = libstringf.so
OUTPUT = StringF

# Default target (runs everything)
all: run

# Step 1: Compile Java source code into .class file
$(JAVA_CLASS): $(JAVA_SRC)
	$(JAVAC) $(JAVA_SRC)

# Step 2: Generate JNI header file using javah
$(JNI_HEADER): $(JAVA_CLASS)
	$(JAVAH) -jni $(OUTPUT)

# Step 3: Compile C code into a shared library
$(SO_FILE): $(C_SRC) $(JNI_HEADER)
	$(CC) $(CFLAGS) -o $(SO_FILE) $(C_SRC)

# Step 4: Run the Java program
run: $(SO_FILE)
	$(JAVA) -Djava.library.path=. $(OUTPUT)

# Clean up generated files
clean:
	rm -f *.class *.h *.so
