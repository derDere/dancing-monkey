SRC = $(wildcard *.cpp)
APP = "dancing-monkey"

All: $(APP)
	@echo Done

$(APP): $(SRC)
	g++ -o $(APP) $(SRC) -D_XOPEN_SOURCE_EXTENDED -lncursesw

test: $(APP)
	./$(APP) debug

install: $(APP)
	cp $(APP) /usr/local/bin/$(APP)

uninstall:
	rm /usr/local/bin/$(APP)
	@echo Done
