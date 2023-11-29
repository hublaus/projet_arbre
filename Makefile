CC = gcc
CFLAGS ?= -Wall -Wextra -Werror
LDLIBS ?=-lm -ltps -lSDL2 -lSDL2_ttf

INCLUDE_PATH = ./include

TARGET_1   = fichier_binaire
TARGET_2   = arbre_couvrant
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SAVEDIR_ARBRE = sauvegarde_arbre_couvrant
SAVEDIR_FICHIER_BINAIRE = sauvegarde_fichier_binaire


SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(INCLUDE_PATH)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

OBJECTS_INT = $(filter-out $(OBJDIR)/ligne_de_commande_fichier_binaire.o,$(OBJECTS))
OBJECTS_ARBRE = $(filter-out $(OBJDIR)/fichier_binaire.o,$(OBJECTS_INT))

all : $(BINDIR)/$(TARGET_1) $(BINDIR)/$(TARGET_2)
	@echo "Liens effectués!"

$(BINDIR)/$(TARGET_1): $(OBJDIR)/fichier_binaire.o $(OBJDIR)/ligne_de_commande_fichier_binaire.o
	mkdir -p $(BINDIR)
	$(CC) -o $@ $^ $(CFLAGS)
	@echo "Liens fichier_binaire effectués!"

$(OBJDIR)/fichier_binaire.o : $(SRCDIR)/fichier_binaire.c
	mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDE_PATH)

$(OBJDIR)/ligne_de_commande_fichier_binaire.o : $(SRCDIR)/ligne_de_commande_fichier_binaire.c
	mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDE_PATH)

$(BINDIR)/$(TARGET_2): $(OBJECTS_ARBRE)
	mkdir -p $(BINDIR)
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)
	@echo "Liens arbre_couvrant effectués!"

$(OBJECTS_ARBRE): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDE_PATH)


doc:
	doxygen Doxyfile

.PHONY: clean
clean :
	rm -f $(OBJDIR)/*.o
	rm -f $(SAVEDIR_ARBRE)/*
	rm -f $(SAVEDIR_FICHIER_BINAIRE)/*
	rm -f $(BINDIR)/$(TARGET_1)
	rm -f $(BINDIR)/$(TARGET_2)
