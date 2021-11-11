GENERATED=antlr4cpp_generated
JAVA=/usr/bin/java
GRAMMAR=qasm3
# This assumes you have antlr-4.9.2-complete.jar in the current directory.
ANTLR4=$(JAVA) -jar antlr-4.9.2-complete.jar


$(GENERATED)/.generated: $(GRAMMAR).g4
	$(ANTLR4) -Dlanguage=Cpp -o $(GENERATED) $(GRAMMAR).g4 -visitor -no-listener
	@touch $(GENERATED)/.generated

$(GENERATED)/%.cpp: $(GENERATED)/.generated;

clean:; rm -rf $(GENERATED)
