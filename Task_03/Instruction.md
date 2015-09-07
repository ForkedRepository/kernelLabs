# Module
## Tools
* list loaded module
* get parameters for snd_ac97_codec module

## First Hello World
Write a simple module that:
- show current kernel version at initialisation
- say Goodbye when unloaded

Try to NOT use macro definition
Tips: Look for file with version in the name

## Modules parameters
* Look for module_param() definition
* Add a param to the previous module.
This parameter configure the number of time the version should be printed

## Coding Style
* use the script scripts/checkpatch.pl --file --no-tree --strict hello.c 
