# corewar_vm

Corewar is a group project, where need write assembler, bot, and virtual machine. Is my vm part.

Core War is a 1984 programming game created by D. G. Jones and A. K. Dewdney in which two or more battle programs (called "warriors") compete for control of a virtual computer. These battle programs are written in an abstract assembly language called Redcode.

## Champions

For demonstration of virtual machine, we need couple of bots on .cor format. On directory "resorces" you find original vm asm and directory with champions. Using asm program, you can compile .s files into .cor.

## VM

To run vm, ypu shoud compile project using Makefile 
```
make
```
After that run program with bots
```
./corewar resources/champs/Gagnant.cor
```
Flag -v run ncurces visualisation
```
./corewar resources/champs/Gagnant.cor -v
```
