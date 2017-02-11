
.SUFFIXES: .cpp .txt

SOURCES = Encounter RPG Dice basic_rpg SystemFunctions groupcheck

.phony: All build

All: $(SOURCES)

build: $(SOURCES)

.cpp.txt:
	G++ -E -P $< > $@

Encounter: Encounter.cpp
	G++ -E -P $< > $@.txt

RPG: RPG.cpp
	G++ -E -P $< > $@.txt
	
Dice: Dice.cpp
	G++ -E -P $< > $@.txt
	
basic_rpg: basic_rpg.cpp
	G++ -E -P $< > $@.txt
	
SystemFunctions: SystemFunctions.cpp
	G++ -E -P $< > $@.txt
	
groupcheck: groupcheck.cpp
	G++ -E -P $< > $@.txt