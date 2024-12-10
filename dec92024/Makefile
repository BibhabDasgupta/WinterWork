# Compiler and tools
CC = gcc
CFLAGS = -shared -fPIC -I/usr/lib/jvm/java-8-openjdk-amd64/include -I/usr/lib/jvm/java-8-openjdk-amd64/include/linux
JAVA = java
JAVAC = javac

# Targets and filenames
TUNNEL_SRC = Tunnel.java
MAIN_SRC = Main.java
TUNNEL_CLASS = Tunnel.class
TUNNEL_HEADER = Tunnel.h
TUNNEL_SO = libtunnel.so
JNI_SRC = Tunnel_jni.c
OUTPUT = Main

# Default target
all: run

# Step 1: Compile Tunnel.java to a .class file
$(TUNNEL_CLASS): $(TUNNEL_SRC)
	$(JAVAC) $(TUNNEL_SRC)

# Step 2: Generate JNI header file
$(TUNNEL_HEADER): $(TUNNEL_CLASS)
	$(JAVAC) -h . $(TUNNEL_SRC)

# Step 3: Compile Tunnel_jni.c into a shared library
$(TUNNEL_SO): $(JNI_SRC) $(TUNNEL_HEADER)
	$(CC) $(CFLAGS) -o $(TUNNEL_SO) $(JNI_SRC) -L. -lpinggy

# Step 4: Compile Main.java
Main.class: $(MAIN_SRC)
	$(JAVAC) $(MAIN_SRC)

# Step 5: Run the program
run: $(TUNNEL_SO) Main.class
	$(JAVA) -Djava.library.path=. $(OUTPUT)

# Clean up generated files
clean:
	rm -f *.class *.h *.so
